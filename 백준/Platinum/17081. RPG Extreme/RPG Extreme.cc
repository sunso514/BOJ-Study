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
#define test "test "
#define endl "\n"
using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define MAPVAL g_map[player.loc_x][player.loc_y]

int N, M;



struct MapInfo {
    enum tile_type {
        NUL,
        BOX,
        TRAP,
        MONSTER,
        BOSS,
        WALL,
        PLAYER
    };
    tile_type type_info = NUL;

    string name;
    int attack, defense, mhealth, exp;

};

class Player;
class Enemy;

class Player {
public:
    int first_x, first_y, loc_x, loc_y, level, exp, health, maxhealth, attack, defense, a_attack, a_defense;
    string acc_slot[4];
    pair<int, int> movement[4];

    int damaged(int damage, Enemy& attacker);   

    // constructor
    Player()
    {
        level = 1;
        exp = 0;
        health = 20;
        maxhealth = 20;
        attack = 2;
        defense = 2;

        // 장비로인한 추가 공/방어력
        a_attack = 0;
        a_defense = 0;

        for (int i = 0; i < 4; i++) acc_slot[i] = "NULL";

        // L, R, U, D
        movement[0] = { 0, -1 };
        movement[1] = { 0, 1 };
        movement[2] = { -1, 0 };
        movement[3] = { 1, 0 };
    }

    // 악세사리 보유 여부
    int have_acc(string acc) {
        for (int i = 0; i < 4; i++) {
            if (acc_slot[i] == acc) return i;
        }
        return -1;
    }


    // 플레이어 힐 받음
    void heal(int val) {
        this->health = this->health + val > this->maxhealth ? this->maxhealth : this->health + val;
    }



    bool trap_damage() { // false : 사망
        int damage;
        if (have_acc("DX") == -1) damage = 5;
        else damage = 1;
        //cout << "acc debug : " << have_acc("DX") << damage <<  endl;
        health -= damage;
        health = max(health, 0);
        if (health <= 0) {
            int getRe = have_acc("RE");
            // 환생!
            if (getRe != -1) {
                acc_slot[getRe] = "NULL";
                this->loc_x = this->first_x;
                this->loc_y = this->first_y;
                heal(1000000007);
                return true;
            }
            else return false; // 사망 후 게임 종료 처리
        }
        else return true;
    }

    // 경험치 획득
    void getExp(int val) {
        exp += have_acc("EX") != -1 ? val * 1.2 : val;

        // level up
        if (exp >= 5 * level) {
            level += 1;
            maxhealth += 5;
            attack += 2;
            defense += 2;
            heal(1000000);
            exp = 0;
        }
    }
};
 

class Enemy {
public:
    int loc_x, loc_y, attack, defense, maxhealth, health, reward;
    bool boss;
    string name;

    bool damaged(int damage, Player& attacker, bool first, MapInfo::tile_type& tile);
    Enemy(int x, int y, string mname, int atk, int def, int m_h, int xp, bool bval) {
        this->loc_x = x;
        this->loc_y = y;
        this->name = mname;
        this->attack = atk;
        this->defense = def;
        this->maxhealth = m_h;
        this->health = m_h;
        this->reward = xp;
        this->boss = bval;
    }
    void heal(int val) {
        if (val == -1) health = maxhealth;
        else health = health + val > maxhealth ? maxhealth : health + val;
    }
};




class Game {
public:
    Player player;
    vector<vector<MapInfo>> g_map;

    int turn, box_amount, monster_amount;
    string command;

    void test_method();


    Game(int max_x, int max_y) {
        Player player = Player();
        g_map.resize(N, vector<MapInfo>(M));

        turn = 0;
        box_amount = 0;
        monster_amount = 0;
    }

    // 입력 받는 부분
    void new_game() {
        for (int i = 0; i < N; i++) {
            string mapstr;
            cin >> mapstr;
            for (int j = 0; j < M; j++) {
                if (mapstr[j] == 'M' || mapstr[j] == '&') monster_amount++;
                if (mapstr[j] == '.') g_map[i][j].type_info = MapInfo::tile_type::NUL;
                if (mapstr[j] == '&') g_map[i][j].type_info = MapInfo::tile_type::MONSTER;
                if (mapstr[j] == 'B') {
                    g_map[i][j].type_info = MapInfo::tile_type::BOX;
                    box_amount++;
                }
                if (mapstr[j] == 'M') g_map[i][j].type_info = MapInfo::tile_type::BOSS;
                if (mapstr[j] == '#') g_map[i][j].type_info = MapInfo::tile_type::WALL;
                if (mapstr[j] == '^') g_map[i][j].type_info = MapInfo::tile_type::TRAP;
                if (mapstr[j] == '@') {
                    g_map[i][j].type_info = MapInfo::tile_type::NUL;
                    player.first_x = i;
                    player.first_y = j;
                    player.loc_x = i;
                    player.loc_y = j;
                }
            }
        }
        cin >> command;
        //cout << monster_amount << " " << box_amount;
        for (int i = 0; i < monster_amount; i++) {
            int x, y, atk, def, hp, xpget;
            string mon_name;
            cin >> x >> y >> mon_name >> atk >> def >> hp >> xpget;
            x--; y--;
            g_map[x][y].name = mon_name;
            g_map[x][y].defense = def;
            g_map[x][y].attack = atk;
            g_map[x][y].mhealth = hp;
            g_map[x][y].exp = xpget;
        }

        for (int i = 0; i < box_amount; i++) {
            int x, y;
            string typ;
            cin >> x >> y >> typ;
            x--; y--;
            if (typ == "O") {
                string acc_ef; 
                cin >> acc_ef;
                g_map[x][y].name = acc_ef;
            }
            else {
                int e_val; 
                cin >> e_val;
                g_map[x][y].name = typ;
                typ == "W" ? g_map[x][y].attack = e_val : g_map[x][y].defense = e_val;
            }
        }
    }




    void open_box(MapInfo box) {
        //cout << "Name Debug : " << box.name << endl;
        if (box.name[0] == 'W') player.a_attack = box.attack;
        else if (box.name[0] == 'A') player.a_defense = box.defense;
        else { // 악세서리
            if (player.have_acc(box.name) == -1 && player.have_acc("NULL") != -1) {
                player.acc_slot[player.have_acc("NULL")] = box.name;
            }
        }
    }

    void print(string result) { 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i == player.loc_x && j == player.loc_y) {
                    if (player.health > 0) {
                        cout << "@";
                        continue;
                    }
                }
                switch(g_map[i][j].type_info) {
                    case MapInfo::tile_type::NUL:
                        cout << ".";
                        break;
                    case MapInfo::tile_type::WALL:
                        cout << "#";
                        break;
                    case MapInfo::tile_type::BOX:
                        cout << "B";
                        break;
                    case MapInfo::tile_type::MONSTER:
                        cout << "&";
                        break;
                    case MapInfo::tile_type::BOSS:
                        cout << "M";
                        break;
                    case MapInfo::tile_type::TRAP:
                        cout << "^";
                        break;
                }
            }
            cout << endl;
        }
        cout << "Passed Turns : " << turn << endl;
        cout << "LV : " << player.level << endl;
        cout << "HP : " << player.health << "/" << player.maxhealth << endl;
        cout << "ATT : " << player.attack << "+" << player.a_attack << endl;
        cout << "DEF : " << player.defense << "+" << player.a_defense << endl;
        cout << "EXP : " << player.exp << "/" << player.level * 5 << endl;
        
        if (result == "Continue_Message") cout << "Press any key to continue.";
        else if (result == "Win_Message") cout << "YOU WIN!";
        else cout << "YOU HAVE BEEN KILLED BY " << result << "..";
    }

    int start_combat(Enemy& monster) {
        // 첫 턴은 특수 효과가 있다.
        int evnt = 0;
        if (monster.boss == true) if (player.have_acc("HU") != -1) {
            player.heal(10000000);
        }
        if (monster.damaged(player.attack + player.a_attack, player, true, MAPVAL.type_info) == true) {
            
           if (player.have_acc("HU") == -1 || monster.boss != true) { // 첫 턴 회피가 불가피하다면
                evnt = player.damaged(monster.attack, monster);
                if (evnt == 1) { // game over
                    this->print(monster.name);
                    return 1;
                }
                else if (evnt == 2) return 2;
            }
        }
        else return 0;
        while (true) {
            if (monster.damaged(player.attack + player.a_attack, player, false, MAPVAL.type_info) == true) {
                evnt = player.damaged(monster.attack, monster);
                if (evnt == 1) {
                    this->print(monster.name);
                    return 1;
                }
                else if (evnt == 2) return 2;
            }
            else return 0;
        }

    }
    bool player_turn(int val) { // true : 다음 턴  false : 턴 중지
        this->turn++;

        // 명령에 따라 움작인다.
        int tmp_x = player.loc_x + player.movement[val].first;
        int tmp_y = player.loc_y + player.movement[val].second;

        // 그리드 밖으로 나가지 않는다면
        if (tmp_x >= 0 && tmp_x < N && tmp_y >= 0 && tmp_y < M && this->g_map[tmp_x][tmp_y].type_info != MapInfo::tile_type::WALL) {
            player.loc_x = tmp_x;
            player.loc_y = tmp_y;
        }
        // event listening
        if (g_map[player.loc_x][player.loc_y].type_info == MapInfo::tile_type::BOX) {
            open_box(g_map[player.loc_x][player.loc_y]);
            g_map[player.loc_x][player.loc_y].type_info = MapInfo::tile_type::NUL;
        }
        else if (g_map[player.loc_x][player.loc_y].type_info == MapInfo::tile_type::TRAP) {
            if (player.trap_damage() == false) { // 사망시
                this->print("SPIKE TRAP");
                return false;
            }
        }
        else if (g_map[player.loc_x][player.loc_y].type_info == MapInfo::tile_type::BOSS) {
            Enemy Monster = Enemy(player.loc_x, player.loc_y, MAPVAL.name, MAPVAL.attack, MAPVAL.defense, MAPVAL.mhealth, MAPVAL.exp, true);
            int comb_res = start_combat(Monster);
            if (comb_res == 0) {
                this->print("Win_Message");
                return false;
            }
            else if (comb_res == 2) return true;
            else return false;
        }
        else if (g_map[player.loc_x][player.loc_y].type_info == MapInfo::tile_type::MONSTER) {
            Enemy Monster = Enemy(player.loc_x, player.loc_y, MAPVAL.name, MAPVAL.attack, MAPVAL.defense, MAPVAL.mhealth, MAPVAL.exp, false);
            int comb_res = start_combat(Monster);
            //cout << endl << "Combat Result == " << comb_res << endl;
            if (comb_res == 0 || comb_res == 2) return true;
            else return false;
        }
        return true;
    }

    void start_game() {
        bool game_continue = false;
        for (int i = 0; i < command.length(); i++) {
            
            
            
            // L, R, U, D
            if (this->command[i] == 'L') game_continue = player_turn(0);
            if (this->command[i] == 'R') game_continue = player_turn(1);
            if (this->command[i] == 'U') game_continue = player_turn(2);
            if (this->command[i] == 'D') game_continue = player_turn(3);

            if (game_continue == false) break;

            //this->print("Debug_Message");
            //string testms;  cin >> testms;
        }

        if (game_continue == true)this->print("Continue_Message");
    }
};

// 플레이어 데미지 받음
int Player::damaged(int damage, Enemy& attacker) {
    damage = max(1, damage - (this->defense + this->a_defense));

    this->health -= damage;
    this->health = max(this->health, 0);

    if (this->health <= 0) {
        int getRe = have_acc("RE");

        // 환생!
        if (getRe != -1) {
            acc_slot[getRe] = "NULL";
            this->loc_x = this->first_x;
            this->loc_y = this->first_y;
            heal(1000000007);

            // 적군 힐 하는거 만들어야함
            attacker.heal(-1);
            return 2; // 환생 후 전투 종료
        }
        else return 1; // 사망 후 게임 종료 처리
    }
    return 0; // 게임 진행
}
bool Enemy::damaged(int damage, Player& attacker, bool first, MapInfo::tile_type& tile) {
    int d_multi = 1;
    if (first == true) {
        if (attacker.have_acc("CO") != -1) {
            d_multi++;
            if (attacker.have_acc("DX") != -1)  d_multi++;
        }
    }
    this->health -= max(1, damage * d_multi - this->defense);
    if (this->health <= 0) {
        // 죽는 이벤트  
        attacker.getExp(this->reward);
        if (attacker.have_acc("HR") != -1) attacker.heal(3);
        tile = MapInfo::tile_type::NUL;
        return false;
    }
    return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    Game game = Game(N, M);

    game.new_game();
    game.start_game();

}