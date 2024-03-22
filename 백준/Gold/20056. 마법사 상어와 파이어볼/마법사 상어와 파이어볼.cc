#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <deque>
#include <set>
#include <tuple>

#include <bitset>

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

#define TEST cout << "test\n";
#define X2 (fb.x + (dx[fb.direction] == -1 ? N - 1 : dx[fb.direction]) * fb.speed) % N
#define Y2 (fb.y + (dy[fb.direction] == -1 ? N - 1 : dy[fb.direction]) * fb.speed) % N


int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1 , -1, -1 };

int N, M, K;





// mass(질량)
struct fireball {
	int x, y, mass, speed, direction;
};

vector<vector<vector<fireball>>> grid;

void check_que_info(queue<fireball> tmp) {
	cout << "===== 큐의 현재 상황 확인 =====\n";
	while (!tmp.empty()) {
		fireball fb = tmp.front();
		tmp.pop();
		cout << "x y mass dir speed : " << fb.x << " " << fb.y << " " << fb.mass << " " << fb.direction << " " << fb.speed << endl;
	}
	cout << "==============================\n";
}

void check_grid_info() {
	cout << "===== 그리드의 현재 상황 확인 =====\n";
	fireball fb;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		if (grid[i][j].size() > 0) cout << "그리드 발견! size :" << grid[i][j].size() << endl;
		for (int k = 0; k < grid[i][j].size(); k++) {
			fb = grid[i][j][k];
			cout << "x y mass dir speed : " << fb.x << " " << fb.y << " " << fb.mass << " " << fb.direction << " " << fb.speed << endl;
		}
	}
	cout << "==============================\n";
}

// 파이어볼 보내기
void push_fireball() {
	
	// 한 번에 담았다가 보내기 위해 queue에 보낼 위치를 저장
	queue<fireball> tmp;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		while (grid[i][j].size() > 0) {
			fireball fb = grid[i][j].back();
			grid[i][j].pop_back();


			int X = (fb.x + (dx[fb.direction] == -1 ? N - 1 : dx[fb.direction]) * fb.speed) % N;
			int Y = (fb.y + (dy[fb.direction] == -1 ? N - 1 : dy[fb.direction]) * fb.speed) % N;

			/*
			int X = fb.x + dx[fb.direction] * (fb.speed % N);
			int Y = fb.y + dy[fb.direction] * (fb.speed % N);
			if (X > 0) X %= N;
			if (Y > 0) Y %= N;
			if (X < 0) X = N - abs(X);
			if (Y < 0) Y = N - abs(Y);
			*/
			tmp.push({ X, Y, fb.mass, fb.speed, fb.direction });
		}
	}

	//check_que_info(tmp);
	while (!tmp.empty()) {
		fireball fb = tmp.front();
		tmp.pop();
		grid[fb.x][fb.y].push_back({ fb.x, fb.y, fb.mass, fb.speed, fb.direction });
	}
}

// 한 위치에 2개 이상일 경우 쪼개고 다시 원래 자리에 넣기
void split_fireball() {
	fireball fb;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		if (grid[i][j].size() < 2) continue;

		int amount = grid[i][j].size();
		int mass = 0;
		int speed = 0;
		int first_dir = grid[i][j].back().direction;


		bool samedir = true;
		while (!grid[i][j].empty()) {
			fb = grid[i][j].back();
			grid[i][j].pop_back();

			mass += fb.mass;
			speed += fb.speed;
			if (fb.direction % 2 != first_dir % 2) {
				samedir = false;
			}

		}

		mass /= 5;
		if (mass == 0) continue;
		speed /= amount;

		for (int k = 0; k < 4; k++) {
			int dir = ((samedir == true) ? 0 : 1) + 2 * k;
			grid[i][j].push_back({ fb.x, fb.y, mass, speed, dir });
		}
	}
}

int get_sum() {
	int ans = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		for (int k = 0; k < grid[i][j].size(); k++) {
			ans += grid[i][j][k].mass;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	grid.resize(N, vector<vector<fireball>>(N, vector<fireball>(0)));


	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		r--; c--;
		grid[r][c].push_back({ r, c, m, s, d });
	}

	for (int tm = 0; tm < K; tm++) {
		//cout << "Turn : " << tm + 1 << endl;
		//check_grid_info();
		push_fireball();
		
		//cout << get_sum();
		split_fireball();
		
		//cout << get_sum();
		//check_grid_info();
	
		//cout << "Turn End \n";
	}
	// 남은 질량 출력
	cout << get_sum();
	return 0;
}