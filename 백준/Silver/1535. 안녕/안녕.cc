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

int ans = 0;
int N;

vector<int> health;
vector<int> joy;

void getans(int now, int joyv, int healthv) {
    if (healthv < 1) return;
    if (now >= N) {
        ans = max(ans, joyv);
        return;
    }
    getans(now + 1, joyv, healthv);
    getans(now + 1, joyv + joy[now], healthv - health[now]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    
    FOR(i, N) {
        int a; cin >> a;
        health.push_back(a);
    }
    FOR(i, N) {
        int b; cin >> b;
        joy.push_back(b);
    }
    getans(0, 0, 100);
    cout << ans;
}


