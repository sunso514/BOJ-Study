
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

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

struct SLoc {
    int row, col, dir, heat;
};

struct Loc {
    int row, col, dir;
};


int R, C, K, W;
vector<vector<int>> temp; // 현재 방 온도 배열

vector<Loc> heater; // 온풍기들 좌표
vector<Loc> target; // 온도 알아야하는 공간 좌표

vector<vector<vector<bool>>> wall; // 우 하 좌 상

vector<vector<int>> total_heatInc; // 모든 온풍기의 온도 증가량

int dx_wind[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy_wind[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };

void show_temp() {
    cout << "\n";
    FOR(i, R) {
        FOR(j, C) {
            cout << temp[i][j] << " ";
        }
        cout << "\n";
    }
}

// 열의 이동이 가능한지 체크 inc : dir + inc를 위한 변수
bool thermal_conduction(int row, int col, int dir, int inc){
    int tmp_x = row + dx_wind[(dir * 2 + inc) % 8];
    int tmp_y = col + dy_wind[(dir * 2 + inc) % 8];
    if (tmp_x < 0 || tmp_x >= R || tmp_y < 0 || tmp_y >= C) return false;

    // 바로 앞에 벽이 있다면 퍼질 수 없음.
    if (wall[tmp_x][tmp_y][(dir + 2) % 4] == true) return false;
    if (inc == 0 && wall[row][col][(dir + 3) % 4] == true) return false;
    if (inc == 2 && wall[row][col][(dir + 1) % 4] == true) return false;
    return true;
}

void heat_decrease() {
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    int sx = 0;
    int sy = 1;
    int dir = 0;
    while (true) {
        temp[sx][sy] = max(temp[sx][sy] - 1, 0);
        if (sx == 0 && sy == 0) break;
        if (sx + dx[dir] < 0 || sy + dy[dir] < 0 || sx + dx[dir] >= R || sy + dy[dir] >= C) dir++;
        sx = sx + dx[dir];
        sy = sy + dy[dir];
    }
}

void diffusion() {
    vector<vector<int>> tmp_temp(R, vector<int>(C, 0));
    FOR(i, R) FOR(j, C) {
        int heat = temp[i][j];
        
        //tmp_temp[i][j] += heat;
        // dir을 2개만 쓴 이유는 온도 확산은 1번만 일어나지만 위 아래를 모두 체크할 경우 변화가 2회 일어난다. ( 가설 )
        for (int dir = 0; dir < 2; dir++) {
            if (thermal_conduction(i, j, dir, 1) == true) {
                int new_x = i + dx_wind[(dir * 2 + 1) % 8];
                int new_y = j + dy_wind[(dir * 2 + 1) % 8];

                
                if (new_x < 0 || new_y < 0 || new_x >= R || new_y >= C) continue;

                // 두 칸의 온도 차이
                int diff = abs(temp[new_x][new_y] - temp[i][j]);
                if (diff / 4 < 1) continue;
                if (temp[new_x][new_y] > temp[i][j]) {
                    tmp_temp[new_x][new_y] -= diff / 4;
                    tmp_temp[i][j] += diff / 4;
                }
                else {
                    tmp_temp[new_x][new_y] += diff / 4;
                    tmp_temp[i][j] -= diff / 4;
                }
            }
        }
    }
    
    FOR(i, R) FOR(j, C) temp[i][j] += tmp_temp[i][j];

}

// 모든 온풍기가 확산되고 증가하는 온도를 미리 계산
void cal_heaters() {
    // 모든 온풍기의 결과를 total_inc에 저장함
    for (auto ht : heater) {
        vector<vector<int>> tmp_temp(R, vector<int>(C, 0));
        queue<SLoc> que;

        // 온풍기가 바라보는 방향 앞에 열기 5 설치
        int front_x = ht.row + dx_wind[(ht.dir * 2 + 1) % 8];
        int front_y = ht.col + dy_wind[(ht.dir * 2 + 1) % 8];

        que.push({ front_x, front_y, ht.dir, 4 });

        // bfs
        tmp_temp[front_x][front_y] = 5;
        total_heatInc[front_x][front_y] += 5;

        //cout << "TEST BFS START\n";

        while (!que.empty()) {
            SLoc tmp = que.front();
            que.pop();
            if (tmp.heat <= 0) continue;

            for (int i = 0; i < 3; i++) {

                // 열 전도가 가능하다면
                if (thermal_conduction(tmp.row, tmp.col, tmp.dir, i) == true) {
                    int new_x = tmp.row + dx_wind[(tmp.dir * 2 + i) % 8];
                    int new_y = tmp.col + dy_wind[(tmp.dir * 2 + i) % 8];
                    if (new_x < 0 || new_y < 0 || new_x >= R || new_y >= C) continue;

                    // 이미 방문했으면 pass
                    if (tmp_temp[new_x][new_y] > 0) continue;
                    que.push({ new_x, new_y, tmp.dir, tmp.heat - 1 });
                    tmp_temp[new_x][new_y] = tmp.heat;
                    total_heatInc[new_x][new_y] += tmp.heat;
                }
            }
        }
    }
}

bool check_goals() {
    for (auto i : target) {
        if (temp[i.row][i.col] < K) return false;
    }
    return true;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> R >> C >> K;
    temp.resize(R, vector<int>(C));
    wall.resize(R, vector<vector<bool>>(C, vector<bool>(4)));
    total_heatInc.resize(R, vector<int>(C, 0));

    FOR(i, R) FOR(j, C) {
        int a; cin >> a;

        if (a == 0) continue;

        // 조사해야하는 온도 칸 입력
        if (a == 5) {
            target.push_back({ i, j, -1 });
            continue;
        }
        // 오, 왼, 위, 아래 온풍기 입력 012 234 456 670
        int tmp_lst[] = { 0, 2, 3, 1 };
        heater.push_back({ i, j, tmp_lst[a-1] });
    }

    // 벽 설정
    cin >> W;
    FOR(i, W) {
        int r, c, t;
        cin >> r >> c >> t;
        r--; c--;
        if (t == 0) {
            wall[r][c][3] = true;
            wall[r-1][c][1] = true;
        }
        else {
            wall[r][c][0] = true;
            wall[r][c + 1][2] = true;
        }
    }


    // 온풍기 온도 상승치 전처리
    cal_heaters();
    int chocolate = 0;
    while (true) {
        
        // 온풍기 가동
        FOR(i, R) FOR(j, C) temp[i][j] += total_heatInc[i][j];
        
        // 온도가 조절됨
        diffusion();

        // 가장자리 온도가 1씩 감소함
        heat_decrease();

        // 초콜릿을 먹음
        chocolate++;
        if (chocolate > 100) break;

        // 온도를 조사
        if (check_goals() == true) break;
    }

    cout << chocolate;
    return 0;
}
    