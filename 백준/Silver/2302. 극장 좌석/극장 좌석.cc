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

#include <bitset>

#define test "test "
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;

    vector<int> dp(N + 1, 1);
    vector<bool> vip(N + 1);
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        vip[a] = true;
    }
    
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    long long ans = 1;

    if (M > 0) {
        int pointer = 1;
        for (int i = 1; i <= N; i++) {
            if (vip[i] == true) {
                ans *= dp[i - pointer];
                pointer = i+1;
            }
        }
        ans *= dp[N - pointer + 1];
    }
    else { ans = dp[N]; }
    cout << ans;
}


