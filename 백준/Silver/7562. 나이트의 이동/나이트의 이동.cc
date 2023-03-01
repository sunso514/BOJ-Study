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



#define test "test "
#define endl "\n"

using namespace std;
const int INF = 999999999;

struct Location {
    int x, y;
};

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

queue<Location> que;
vector<vector<int>> graph;

int N, M;
int bfs(int goalx, int goaly) {
    Location loc;

    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int tx = loc.x + dx[i];
            int ty = loc.y + dy[i];
            
            if (ty >= 0 && tx >= 0 && tx < N && ty < N) {
                if (graph[tx][ty] != -1) continue;
                que.push({ tx, ty });
                graph[tx][ty] = graph[loc.x][loc.y] + 1;
                //cout << graph[tx][ty] << endl;
                if (goalx == tx && goaly == ty) {
                   // cout << test;
                    //cout << graph[tx][ty] << " " << tx << " " << ty << endl;
                    return graph[goalx][goaly];
                }
            }
        }
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int tme; cin >> tme;
    for (int i = 0; i < tme; i++) {
        cin >> N;
        graph.resize(N, vector<int>(N));
        fill(graph.begin(), graph.end(), vector<int>(N, -1));
        int a, b; cin >> a >> b;
        que.push({ a, b});
        graph[a][b] = 0;
        int x, y; cin >> x >> y;

        if (a == x && b == y) cout << 0 << endl;
        else {
            int res = bfs(x, y);
            cout << res << endl;
        }
        while (!que.empty()) que.pop();
    }

    return 0;
}