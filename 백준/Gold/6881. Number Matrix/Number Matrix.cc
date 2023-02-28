#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("urnoll-loops")


#define test "test "
#define endl "\n"

using namespace std;
struct Location {
    int x, y;
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };

queue<Location> que;
vector<vector<int>> graph;
vector<vector<bool>> visit;

int N, M;

bool bfs(int tma, int tmb, int tmc) {
    Location loc;

    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int tx = loc.x + dx[i];
            int ty = loc.y + dy[i];
            if (ty >= 0 && tx >= 0 && tx < N && ty < M && !visit[tx][ty]) {
                if (graph[tx][ty] != tma && graph[tx][ty] != tmb && graph[tx][ty] != tmc) continue;
                que.push({ tx, ty });
                visit[tx][ty] = true;
                if (tx == N-1) {
                    return true;
                }
            }
        }
    }
    return false;
}

void bfsReady(int i, int j, int k) {
    for (int o = 0; o < M; o++) {
        if (graph[0][o] == i || graph[0][o] == j || graph[0][o] == k) {
            que.push({ 0, o });
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> M >> N;
    graph.resize(N, vector<int>(M));
    visit.resize(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                bfsReady(i, j, k);
                if (bfs(i, j, k) == true) {
                    cout << i << " " << j << " " << k;
                    return 0;
                }
                else {
                    fill(visit.begin(), visit.end(), vector<bool>(M, false));
                }
            }
        }
    }
    cout << "-1 -1 -1";
}