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

bool oper(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<pair<int, int>> a;

    FOR(i, N) {
        int v; cin >> v;
        a.push_back({ v, i });
    }
    sort(a.begin(), a.end());

    vector<int> b(N);

    FOR(i, N) b[a[i].second] = i;
    for (auto i : b) cout << i << " ";


}


