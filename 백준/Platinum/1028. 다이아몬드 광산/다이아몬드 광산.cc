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


int N, M;
vector<vector<pair<int, int>>> dp;


int dx[2] = { 1, -1 };

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
   
    cin >> N >> M;
    dp.resize(N, vector<pair<int, int>>(M));
    int res = 0;
    string gets;
    for (int i = 0; i < N; i++) {
        cin >> gets;
        for (int j = 0; j < M; j++) {
            if (gets[j] == '1') {
                if (res == 0) res++;
                dp[i][j] = { 1, 1 }; // first: right  // second: left
                if (i - 1 >= 0 && j + 1 < M)  dp[i][j].first = dp[i - 1][j + 1].first + 1;
                if (i - 1 >= 0 && j - 1 >= 0)  dp[i][j].second = dp[i - 1][j - 1].second + 1;
            }
        }
    }
    /*
    cout << endl;
    FOR(i, N) {
        FOR(j, M) cout << dp[i][j].first;
        cout << endl;
    }
    cout << endl;
    FOR(i, N) {
        FOR(j, M) cout << dp[i][j].second;
        cout << endl;
    }
    */
    FOR(i, N) FOR(j, M) {
        if (dp[i][j].first == 0 && dp[i][j].second == 0) continue; // 다이아몬드를 구성하기 위한 최소 숫자보다 작다면 컷
        int c_len = min(dp[i][j].first, dp[i][j].second); 
        for (int jonggang = c_len; jonggang > res; jonggang--) { // 최적화를 위해서 res 보다 크기가 작으면 바로 컷
            int tmp_y = i - jonggang + 1;
            int tmp_rx = j - jonggang + 1; // first
            int tmp_lx = j + jonggang - 1; // seconds

            // jonggang 만큼 떨어진게 jonggang이상이면 다이아 완성
           // cout << tmp_y << " " << tmp_rx << " " << tmp_lx << endl;
            if (dp[tmp_y][tmp_rx].first >= jonggang && dp[tmp_y][tmp_lx].second >= jonggang) { 
                res = max(res, jonggang);
            }

        }
    }

    cout << res;
}