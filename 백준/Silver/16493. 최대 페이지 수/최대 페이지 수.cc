
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
#include <iomanip>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;



int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M; cin >> N >> M;

    vector<int> day(M+1), chap(M+1);
    vector<vector<int>> dp(M+1, vector<int>(N+1, 0));

    for (int i = 1; i <= M; i++) cin >> day[i] >> chap[i];

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (j >= day[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - day[i]] + chap[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    
    cout << dp[M][N];

}
