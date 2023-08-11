#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

vector<vector<int>> rgb;
vector<vector<int>> dp;

int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    rgb.resize(N, vector<int>(3));
    dp.resize(N, vector<int>(3, 1000000007));

    FOR(i, N) FOR(j, 3) cin >> rgb[i][j];
    FOR(i, 3)  dp[0][i] = rgb[0][i];

    for (int i = 1; i < N; i++) FOR(j, 3){
        dp[i][j] = min(dp[i - 1][(j + 1) % 3] + rgb[i][j], dp[i][j]);
        dp[i][j] = min(dp[i - 1][(j + 2) % 3] + rgb[i][j], dp[i][j]);
    }
    cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
}