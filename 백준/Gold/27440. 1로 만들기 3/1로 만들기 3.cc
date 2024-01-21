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

struct Loc {
    long long x, time;
};

queue<Loc> que;
map<long long, int> visit;


void bfs() {
    Loc tmp;

    while (!que.empty()) {
        tmp = que.front();
        que.pop();
        
        if (tmp.x == 1) {
            cout << tmp.time;
            return;
        }
        if ((tmp.x % 3 == 0 && tmp.x / 3 > 0) && (visit.find(tmp.x / 3) == visit.end())) {
            que.push({ tmp.x / 3, tmp.time + 1 });
            visit[tmp.x / 3] = 1;
        }
        if ((tmp.x % 2 == 0 && tmp.x / 2 > 0) && (visit.find(tmp.x / 2) == visit.end())) {
            que.push({ tmp.x / 2, tmp.time + 1 });
            visit[tmp.x / 2] = 1;
        }
        if ((tmp.x - 1 > 0) && (visit.find(tmp.x - 1) == visit.end())) {
            que.push({ tmp.x - 1, tmp.time + 1 });  
            visit[tmp.x - 1] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;
    que.push({ N, 0 });
    visit[N] = 1;
    bfs();
}