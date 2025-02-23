#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

struct Location {
    int x, y, timing;
};

// 대각선위 오른쪽 대각선아래 아래
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int R, C, N;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> R >> C >> N;

    vector<string> tmp(R);
    FOR(i, R) cin >> tmp[i];


    // 초기값 설정
    vector<vector<int>> field(R, vector<int>(C, 0));
    FOR(i, R) FOR(j, C) {
        if (tmp[i][j] == 'O') {
            field[i][j] = 3;
            tmp[i][j] = 'O';
        }
        else field[i][j] = 0;
        
    }
    //queue<int> btime;

    for (int time = 2; time <= N; time++) {
        // 3번 행동 : 모든 칸에 폭탄 설치
        if (time % 2 == 0) {
            FOR(i, R) FOR(j, C) {
                if (tmp[i][j] == '.') {
                    tmp[i][j] = 'O';
                    field[i][j] = time + 3;
                }
            }
        }
        else {
            FOR(i, R) FOR(j, C) {
                if (field[i][j] == time) {
                    FOR(k, 4) {
                        int tmp_x = i + dx[k];
                        int tmp_y = j + dy[k];
                        if (tmp_x < 0 || tmp_y < 0 || tmp_x >= R || tmp_y >= C) continue;
                        tmp[tmp_x][tmp_y] = '.';
                    }
                    tmp[i][j] = '.';
                    field[i][j] = false;
                }
            }
        }
    }

    FOR(i, R) {
        cout << tmp[i] << endl;
    }
}
    