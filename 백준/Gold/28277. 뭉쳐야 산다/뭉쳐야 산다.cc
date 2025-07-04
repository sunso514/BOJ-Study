
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
#include <iomanip>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)
#define INF 1000000009

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, Q; cin >> N >> Q;

    vector<set<int>> sets(N+1);
    for(int i = 1; i <= N; i++){
        int siz; cin >> siz;
        while (siz--) {
            int a; cin >> a;
            sets[i].insert(a);
        }
    }

    while (Q--) {
        int command; cin >> command;
        
        int a, b;
        cin >> a;
        if (command == 1) {
            cin >> b;
            if (sets[a].size() < sets[b].size()) swap(sets[a], sets[b]);

            for (int i : sets[b]) sets[a].insert(i);
            sets[b].clear();
        }
        else cout << sets[a].size() << endl;
    }

}

