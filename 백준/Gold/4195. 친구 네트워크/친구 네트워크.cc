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
#include <ranges>
#define test "test "
#define endl "\n"
using namespace std;

vector<int> parent(200050);
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, K, M;

int Find(int index) {
    if (parent[index] < 0) return index;
    return parent[index] = Find(parent[index]);
}

void Union(int x, int y) {
    int x_p = Find(x);
    int y_p = Find(y);
    if (x_p == y_p) return;
    if (x_p > parent[x_p]) {
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

    int T; cin >> T;
    FOR(i, T) {
        int ti; cin >> ti;
        map<string, int> id;
        fill(parent.begin(), parent.end(), -1);
        FOR(j, ti) {
            string a, b; cin >> a >> b;
            if (id.find(a) == id.end()) id[a] = id.size();
            if (id.find(b) == id.end()) id[b] = id.size();
            Union(id[a], id[b]);
            
            //for (int i = 0; i < 5; i++) cout << parent[i] << " "; 
            if (parent[id[a]] >= 0) cout << abs(parent[parent[id[a]]]) << endl;
            else cout << abs(parent[id[a]]) << endl;
           // cout << (parent[id[a]] < 0) ? abs(parent[id[a]]) : abs(parent[id[b]]);
            //cout << endl;
        }

    }
    

    

}