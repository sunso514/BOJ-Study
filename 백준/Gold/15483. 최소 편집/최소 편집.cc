
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

    string a, b;
    cin >> a >> b;
    int m = a.length();
    int n = b.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int i = 0; i <= n; i++) dp[0][i] = i;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
        }
    }
 
    /*
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[m][n];

}
