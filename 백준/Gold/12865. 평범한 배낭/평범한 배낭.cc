
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
#define INF 1000000009

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> weight(n+1);
    vector<int> value(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
            }

        }
    }
    cout << dp[n][k];
}
