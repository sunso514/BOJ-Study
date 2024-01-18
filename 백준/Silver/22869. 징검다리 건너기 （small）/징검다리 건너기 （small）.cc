#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    vector<int> road(N+1, 0);
    vector<int> dp(N + 1, 1000000007);
    for (int i = 0; i < N; i++) cin >> road[i];

    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] == 1000000007) continue;
        for (int j = i + 1; j < min(N, i+1001); j++) {
            int power = (j - i) * (1 + abs(road[i] - road[j]));
            if (dp[j] > power && power <= K) {
                dp[j] = power;
            }
        }
    }
    if (dp[N - 1] == 1000000007) cout << "NO";
    else cout << "YES";
}