#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Loc{
    int start, end, cost;
};

int N, D;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> D;

    vector<Loc> graph;
    vector<int> dp(10001, 1000000007);


    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (b > D) continue;
        graph.push_back({ a, b, c });
    }
    
    dp[0] = 0;

    for (int i = 0; i < D; i++) {
        for (Loc lc : graph) {
            if (lc.start != i) continue;
            dp[lc.end] = min(dp[lc.end], dp[i] + lc.cost);
        }
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
    cout << dp[D];
}