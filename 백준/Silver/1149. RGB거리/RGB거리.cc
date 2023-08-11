#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vector<vector<int>> rgb(N, vector<int>(3));
    vector<vector<int>> dp(N, vector<int>(3, 1000000007));
    
    FOR(i, N) FOR(j, 3) cin >> rgb[i][j];
    FOR(i, 3)  dp[0][i] = rgb[0][i];

    for (int i = 1; i < N; i++) FOR(j, 3) FOR(k, 2)
        dp[i][j] = min(dp[i - 1][(j + k + 1) % 3] + rgb[i][j], dp[i][j]);
        
    cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
}