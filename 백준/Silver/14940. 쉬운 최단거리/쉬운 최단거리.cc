#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

struct loc {
    int x, y, depth;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M));
    vector<vector<int>> visit(N, vector<int>(M, -1));

    loc start = { -1, -1, 0 };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                start = { i, j, 0 };
            }
            if (graph[i][j] == 0) visit[i][j] = 0;
        }
    }

    queue<loc> que;
    que.push(start);
    visit[start.x][start.y] = 0;

    while (!que.empty()) {

        loc now = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + now.x;
            int ny = dy[i] + now.y;
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visit[nx][ny] != -1) continue;
            if (graph[nx][ny] != 1) continue;

            que.push({ nx, ny, now.depth + 1});
            visit[nx][ny] = now.depth + 1;
            
        }

    }
    FOR(i, N) {
        FOR(j, M) {
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
}

