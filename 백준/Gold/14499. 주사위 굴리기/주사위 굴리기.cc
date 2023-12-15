#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Map {
public:
    explicit Map(vector<vector<int>> mp) : map(mp) { }

    int getMapData(pair<int, int> loc) {
        return this->map[loc.first][loc.second];
    }

    void setMapData(pair<int, int> loc, int value) {
        this->map[loc.first][loc.second] = value;
    }

private:
    vector<vector<int>> map;
};

class Dice {
public:
    explicit Dice(const int x, const int y) : nowX(x), nowY(y) { init(); }


    void moveDice(const int dir) {
        vector<int> tmp_dice;
        // 동, 오른쪽으로 이동
        if (dir == 0) {
            tmp_dice = { dice[3], dice[1], dice[0], dice[5], dice[4], dice[2] };
        }
        // 서, 왼쪽으로 이동
        else if (dir == 1) {
            tmp_dice = { dice[2], dice[1], dice[5], dice[0], dice[4], dice[3] };
        }
        // 북, 위 쪽으로 이동
        else if (dir == 2) {
            tmp_dice = { dice[4], dice[0], dice[2], dice[3], dice[5], dice[1] };
        }
        // 남, 아래 쪽으로 이동
        else{
            tmp_dice = { dice[1], dice[5], dice[2], dice[3], dice[0], dice[4] };
        } 

        this->dice = tmp_dice;
    }

    pair<int, int> getLoc() {
        return { this->nowX, this->nowY };
    }

    void setLoc(int x, int y) {
        this->nowX = x;
        this->nowY = y;
    }

    int getDiceNum(int idx) {
        return this->dice[idx];
    }

    void setDiceNum(int idx, int val) {
        this->dice[idx] = val;
    }

private:
    int nowX, nowY;
    vector<int> dice;

    void init() {
        // bottom = index 5
        dice.resize(6, 0);
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int N, M, X, Y, K; 
    cin >> N >> M >> X >> Y >> K;

    vector<vector<int>> mp_info(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mp_info[i][j];
        }
    }

    // 동 서 북 남
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };

    Map map(mp_info);
    Dice dice(X, Y);

    dice.setLoc(X, Y);
    dice.setDiceNum(5, map.getMapData(dice.getLoc()));
    map.setMapData(dice.getLoc(), 0);

    for (int i = 0; i < K; i++) {
        int cmd;
        cin >> cmd;

        pair<int, int> nowLoc = dice.getLoc();

        int tmp_x = nowLoc.first + dx[cmd - 1];
        int tmp_y = nowLoc.second + dy[cmd - 1];

        // pass if dice go out of map
        if (tmp_x < 0 || tmp_y < 0 || tmp_x >= N || tmp_y >= M) continue;

        // set location of dice and roll dice
        dice.setLoc(tmp_x, tmp_y);
        dice.moveDice(cmd - 1);

        // copy bottom number of dice
        if (map.getMapData(dice.getLoc()) == 0) {
            map.setMapData(dice.getLoc(), dice.getDiceNum(5));
        }
        else {
            dice.setDiceNum(5, map.getMapData(dice.getLoc()));
            map.setMapData(dice.getLoc(), 0);
        }

        cout << dice.getDiceNum(0) << "\n";
        
    }

}