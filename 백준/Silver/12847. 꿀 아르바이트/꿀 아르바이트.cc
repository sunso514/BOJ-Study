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

    vector<long long> pay(100002);
    vector<long long> nujuk(100002);

    long long N, M;
    cin >> N >> M;

    FOR(i, N) {
        cin >> pay[i+1];
    }
    nujuk[0] = 0;
    nujuk[1] = pay[1];
    for (int i = 1; i <= N; i++) {
        nujuk[i] = pay[i] + nujuk[i - 1];

    }
    long long ans = 0;
    for (int i = M; i <= N; i++) {
        ans = max(ans, nujuk[i] - nujuk[i - M]);
    }
    cout << ans;
}