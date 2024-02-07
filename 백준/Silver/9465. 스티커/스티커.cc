#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int a; cin >> a;
        vector<vector<int>> stk(2, vector<int>(a));
        
        for (int i = 0; i < a; i++) cin >> stk[0][i];
        for (int i = 0; i < a; i++) cin >> stk[1][i];
        if (a == 1) {
            cout << max(stk[0][0], stk[1][0]) << endl;
            continue;
        }
        vector<vector<int>> dp = stk;

        int maxv = 0;
        for (int i = 0; i < a - 1; i++) {
            dp[0][i + 1] = max(dp[1][i] + stk[0][i + 1], dp[0][i + 1]);
            dp[1][i + 1] = max(dp[0][i] + stk[1][i + 1], dp[1][i + 1]);
            maxv = max(max(dp[0][i + 1], dp[1][i + 1]), maxv);
            if (i < a - 2) {
                for (int j = 0; j < 4; j++) {
                    dp[j / 2][i + 2] = max(dp[j % 2][i] + stk[j / 2][i + 2], dp[j / 2][i + 2]);
                    maxv = max(dp[j / 2][i + 2], maxv);
                }
            }
        }
        cout << maxv << endl;
    }
}
