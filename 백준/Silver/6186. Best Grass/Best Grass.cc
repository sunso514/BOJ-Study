#include <iostream>
#include <queue>
#include <vector>


using namespace std;


int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Location {
    int x, y;
};

queue<Location> que;
vector<vector<int>> graph;

#define X l.x + dx[i]
#define Y l.y + dy[i]
int N, M;

void bfs() {
    Location l;
    while (!que.empty()) {
        l = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            if (X < 0 || Y < 0 || X >= N || Y >= M) continue;
            if (graph[X][Y] == 1) {
                que.push({ X, Y });
                graph[X][Y] = 0;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;

    graph.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string maps; cin >> maps;
        for (int j = 0; j < M; j++) {
            if (maps[j] == '#') graph[i][j] = 1;
            else graph[i][j] = 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 1) {
                que.push({ i, j });
                cnt++;
                bfs();
            }
        }
    }
    cout << cnt;
}