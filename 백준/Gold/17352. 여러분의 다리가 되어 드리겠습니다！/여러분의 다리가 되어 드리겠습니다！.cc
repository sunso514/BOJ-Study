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
#define test "test "
#define endl "\n"
using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, M;

vector<int> parent(300002, -1);

int find(int cord) {
    if (parent[cord] < 0) return cord;
    return parent[cord] = find(parent[cord]);
}

void Union(int x, int y) {
    int x_p = find(x);
    int y_p = find(y);

    if (x_p == y_p) return;
    if (parent[x_p] > parent[y_p]) {
        parent[x_p] += parent[y_p];
        parent[y_p] = x_p;
    }
    else {
        parent[y_p] += parent[x_p];
        parent[x_p] = y_p;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;

    for (int i = 0; i < N-2; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    for (int i = 2; i <= N; i++) {
        if (find(1) != find(i)) {
            cout << 1 << " " << i;
            return 0;
        }
    }
}