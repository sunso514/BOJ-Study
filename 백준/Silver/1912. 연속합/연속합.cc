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
#define test "test "
#define endl "\n"
using namespace std;

#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)


int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;

    vector<int> lst(N + 1);
    vector<int> dp(N + 1);

    FOR(i, N) cin >> lst[i];
    int max = lst[0];
    dp[0] = lst[0];
    for(int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + lst[i] > lst[i] ? dp[i - 1] + lst[i] : lst[i];
        max = dp[i] > max ? dp[i] : max;
    }
    cout << max;
}