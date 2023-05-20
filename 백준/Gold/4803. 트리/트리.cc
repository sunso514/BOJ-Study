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
#include <set>
#define test "test "
#define endl "\n"
using namespace std;

vector<int> parent(501);
vector<bool> check(501);
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)


int ANS;

int Find(int index) {
    if (parent[index] == index) return index;
    return parent[index] = Find(parent[index]);
}
void Union(int x, int y) {
    int x_p = Find(x);
    int y_p = Find(y);
    if (x_p == y_p) {
        check[x_p] = true;
        return;
    }
    parent[x_p] = y_p;
    if (check[x_p] || check[y_p]) {
        check[x_p] = true;
        check[y_p] = true;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int Cse = 0;
    while (true) {
        Cse++;
        int N, M; cin >> N >> M;
        if (N == 0 && M == 0) break;
        FOR(i, N) {
            parent[i] = i;
            check[i] = false;
        }

        FOR(i, M) {
            int a, b; cin >> a >> b;
            Union(a - 1, b - 1);  
        }

        ANS = 0;

        set<int> s;
        FOR(i, N) {
            int par = Find(i);
            if (check[par]) continue;
            if (s.count(par) == 0) {
                s.insert(par);
                ANS++;
            }
        }

        //cout << s.size() << test << endl;
        cout << "Case " << Cse << ": ";
        if (ANS == 0) cout << "No trees.";
        else (ANS == 1) ? cout << "There is one tree." : cout << "A forest of " << ANS << " trees.";
        cout << endl;
   }

}