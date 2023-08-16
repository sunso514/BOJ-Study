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
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, L;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> L;

    int count = 0;
    vector<pair<int, int>> gp;

    FOR(i, N) {
        int a, b;
        cin >> a >> b;
        gp.push_back({ a, b });
    }

    sort(gp.begin(), gp.end());

    int x = 0;

    FOR(i, N) {
        if (x >= gp[i].second) continue;
        x = max(x, gp[i].first);

        while (x < gp[i].second) {
            count++;
            x += L;
        }
    }   

    cout << count;
}