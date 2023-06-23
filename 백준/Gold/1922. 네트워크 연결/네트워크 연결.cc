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

int V, E, T;

vector<int> parent(1003, -1);
int find(int cord) {
    if (parent[cord] < 0) return cord;
    return parent[cord] = find(parent[cord]);
}

bool Union(int x, int y) {
    int x_p = find(x);
    int y_p = find(y);

    if (x_p == y_p) return 0;
    parent[x_p] = y_p;
    return 1;
}

tuple<int, int, int> edge[100003];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = { cost , a, b };
    }
    sort(edge, edge + E);

    int res = 0;
    int cnt_e = 0;
    for (int i = 0; i < E; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];

        if (Union(a, b) == false) continue;
        
        cnt_e++;
        res += cost;
        if (cnt_e == V - 1) break;

    }
    cout << res;
}