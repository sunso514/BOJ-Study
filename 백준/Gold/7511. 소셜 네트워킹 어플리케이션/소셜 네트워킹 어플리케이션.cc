#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n"
using namespace std;

vector<int> parent;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, K, M;

int Find(int index) {
    if (parent[index] < 0) return index;
    return parent[index] = Find(parent[index]);
}

void Union(int x, int y) {
    int x_parent = Find(x);
    int y_parent = Find(y);
    if (x_parent == y_parent) return;
    parent[x_parent] = y_parent;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int tm; cin >> tm;
    
    FOR(i, tm) {
        cout << "Scenario " << i + 1 << ":" << endl;
        cin >> N;
        parent.resize(N + 1);
        fill(parent.begin(), parent.end(), -1);
        cin >> K;
        FOR(j, K) {
            int a, b; cin >> a >> b;
            Union(a, b);
        }
        cin >> M;
        FOR(j, M) {
            int u, v; cin >> u >> v;
            cout << (Find(u) == Find(v)) << endl;
        }
        cout << endl;
    }
}