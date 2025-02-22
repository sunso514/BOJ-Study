#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

// 대각선위 오른쪽 대각선아래 아래
int dx[4] = { -1, 0, 1, 1 };
int dy[4] = { 1, 1, 1, 0 };

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> checker(19, vector<int>(19, 0));
    vector<vector<vector<int>>> ban_check(19, vector<vector<int>>(19, vector<int>(4, 0)));
    
    FOR(i, 19) FOR(j, 19) cin >> checker[i][j];

    FOR(j, 19) FOR(i, 19) {
        int dol = checker[i][j];
        if (dol == 0) continue;
        
        // 4 방향 모두 확인
        FOR(k, 4) {
            if (ban_check[i][j][k] == true) continue;

            int streak = 1;
            for (int p = 1; p <= 5; p++) {
                int tmp_x = i + p * dx[k];
                int tmp_y = j + p * dy[k];
                if (tmp_x < 0 || tmp_y < 0 || tmp_x >= 19 || tmp_y >= 19) break;
                if (dol != checker[tmp_x][tmp_y]) break;
                streak++;
            }

            // 5목일 경우
            if (streak == 5) {
                cout << dol << endl << i + 1 << " " << j + 1;
                return 0;
            }

            // 6목 이상일 경우
            if (streak == 6) {
                for (int p = 0; p <= 18; p++) {
                    int tmp_x = i + p * dx[k];
                    int tmp_y = j + p * dy[k];
                    if (tmp_x < 0 || tmp_y < 0 || tmp_x >= 19 || tmp_y >= 19) break;
                    if (dol != checker[tmp_x][tmp_y]) break;
                    ban_check[tmp_x][tmp_y][k] = true;
                }
            }
            
        }
    }
    cout << 0;
}
    