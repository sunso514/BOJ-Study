#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)
int N;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    vector<int> tab(N);
    vector<int> dp(N, 1);

    FOR(i, N) cin >> tab[i];
    int maxv = 1;

    for (int i = 1; i < N; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (tab[i] > tab[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                maxv = max(maxv, dp[i]);
            }
        }
    }
    cout << maxv;
}