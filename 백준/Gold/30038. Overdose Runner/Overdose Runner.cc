#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N, M, K, S;

struct World{
	char type;
	
	// 몇번째 몬스터가 있는지 체크
	int monsterT = -1;	
};

struct Monster{
	int x, y, health, defense, xp;
};


vector<vector<World>> world;
vector<Monster> monster;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};



// === Player First Setting ==
int p_x = 0;
int p_y = 0;

int power = 5;
int attack_range = 1;
int speed = 1;

int level = 1;
int xp = 0;
int xpneed = 10;

int drugcount = 0;
int overdose = false;
int totalActionP = 0;
int actionP = 0;
// =====================




void getActionP(int num){
	if (overdose == true) {
		actionP += num;
		if (actionP >= 10) {
			overdose = false;
			actionP = 0;
		}
	}
	totalActionP += num;
}

void attack(int ac){
	getActionP(3);
	
	FOR(i, attack_range){
		int attack_x = p_x + dx[ac]*(i+1);
		int attack_y = p_y + dy[ac]*(i+1);
		if (attack_x < 0 || attack_y < 0 || attack_x >= N || attack_y >= M) break;
		if (world[attack_x][attack_y].type == '*') break;
		
		if (world[attack_x][attack_y].type == 'm'){
			int idx = world[attack_x][attack_y].monsterT;
			monster[idx].health -= max(power - monster[idx].defense, 0);
			//cout << "몬스터 공격받음! 남은 체력 : " << monster[idx].health << endl;
			if (monster[idx].health <= 0){
				
				// Set Location empty
				world[attack_x][attack_y].type = '.';
				
				// Gain EXP
				xp += monster[idx].xp;
			}
		}
	}
}

void teleport(int ac){
	
	int nextX = p_x + dx[ac]*(speed);
	int nextY = p_y + dy[ac]*(speed);
	if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) return;
	if (world[nextX][nextY].type == '*' || world[nextX][nextY].type == 'm') return;
	p_x = nextX;
	p_y = nextY;
	getActionP(1);
}
void drug(int ac){
	// speed up
	if (ac == 0) speed += 1;
	else speed = max(0, (speed - 1));
	getActionP(2);
	
	drugcount++;
	if (drugcount == 5){
		overdose = true;
		drugcount = 0;
	}
}


void showMap(){
	FOR(i, N){
		FOR(j, M){
			if (p_x == i && p_y == j) {
				cout << 'p';
				continue;
			}
			cout << world[i][j].type;
		}
		cout << endl;
	}
}

void showInfo(){
	cout << "Level " << level << " ( " <<  xp << "/" << xpneed << " )" << endl;
	cout << "Speed : " << speed << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	//World Setting
	world.resize(N, vector<World>(M));
	
	FOR(i, N)FOR(j, M) {
		cin >> world[i][j].type;
		// 몬스터 처리
		if (world[i][j].type == 'm'){
			world[i][j].monsterT = monster.size();
			monster.push_back({i, j, 0, 0, 0});
		}
		else if (world[i][j].type == 'p'){
			p_x = i;
			p_y = j;
			world[i][j].type = '.';
		}
		
	}
	
	// Monster Stat Setting
	cin >> K;
	FOR(i, K) cin >> monster[i].health;
	FOR(i, K) cin >> monster[i].defense;
	FOR(i, K) cin >> monster[i].xp;
	
	//Game Start
	cin >> S;
	FOR(turn, S){
		string command; cin >> command;
		
		//cout << "Turn : " << turn << endl;
		// unable when OVERDOSE
		if (overdose == false){
			
			//attack
			if (command == "au") attack(0);
			else if (command == "ad") attack(1);
			else if (command == "al") attack(2);
			else if (command == "ar") attack(3);
			
			// drug
			else if (command == "du") drug(0);
			else if (command == "dd") drug(1);
			
			// clear
			else if (command == "c") {
				if (world[p_x][p_y].type == 'g') break;
			}
		}
		
		if (command == "w") getActionP(1);
		//movement
		if (command == "u") teleport(0);
		else if (command == "d") teleport(1);
		else if (command == "l") teleport(2);
		else if (command == "r") teleport(3);
		//showInfo();
		//showMap();
		while(xp >= xpneed){
			xp -= xpneed;
			power += level;
			level++;
			attack_range++;
			xpneed += 10;
		}
	}

	// Show Result
	cout << level << " " << xp << "\n";
	cout << totalActionP << "\n";
	
	showMap();
	FOR(i, monster.size()){
		if (monster[i].health > 0) cout << monster[i].health << " "; 
	}
}