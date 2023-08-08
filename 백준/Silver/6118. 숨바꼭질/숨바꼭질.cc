#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

struct Location {
    int x, depth;
};


int N, M;

vector<vector<int>> graph;
vector<int> visit;
queue<Location> que;

Location maxv = { 1000000007, -1 };
int hcount = 1;

void bfs() {
    
    Location loc;

    while (!que.empty()) {
        loc = que.front();
        que.pop();

        if (maxv.depth <= loc.depth) {
            if (maxv.depth == loc.depth) {
                hcount++;
                if (maxv.x > loc.x) maxv = loc;
            }
            else {
                maxv = loc;
                hcount = 1;
            }
        }
        for (auto k : graph[loc.x]) {
            if (visit[k] == false) {
                que.push({ k, loc.depth + 1 });
                visit[k] = true;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    graph.resize(N+1, vector<int>(0));
    visit.resize(N + 1);

    FOR(i, M) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visit[1] = true;
    que.push({ 1, 0 });

    bfs();
    cout << maxv.x << " " << maxv.depth << " " << hcount;
}