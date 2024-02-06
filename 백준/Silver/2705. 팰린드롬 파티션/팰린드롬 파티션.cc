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

vector<long long> dp(1001, -1);

long long falimPtn(int N) {
    if (dp[N] != -1) return dp[N];
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (((N - i) / 2) * 2 + i == N) sum += falimPtn((N - i) / 2);
    }
    dp[N] = sum + 1;
    return sum + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 2;

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int a;
        cin >> a;
        cout << falimPtn(a) << endl;
    }

}