#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct loc {
    int x, y;
};

vector<vector<int>> graph;
vector<int> speed(10); 
vector<queue<loc>> que;

int N, M, P;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// p : player number
bool bfs(int p, int play_count) {
    bool updated = false;

    while (play_count--) {
        loc now = que[p].front();
        que[p].pop();

        if (graph[now.x][now.y] != 0 && graph[now.x][now.y] != p) continue;

        // 4방향 탐색
        for (int t = 0; t < 4; t++) {
            int nxt_x = now.x + dx[t];
            int nxt_y = now.y + dy[t];

            // 범위 벗어나는 구간, 이미 점령된 곳, 벽 패스
            if (nxt_x < 0 || nxt_y < 0 || nxt_x >= N || nxt_y >= M) continue;
            if (graph[nxt_x][nxt_y] != 0) continue;

            graph[nxt_x][nxt_y] = p;
            updated = true;

            que[p].push({ nxt_x,nxt_y });
        }
    }
    return updated;
}

void debug_grpah() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == -1) cout << "#";
            else if (graph[i][j] == 0) cout << '.';
            else cout << graph[i][j];
        }
        cout << endl;
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> N >> M >> P;
    graph.resize(N, vector<int>(M, 0));
    que.resize(P + 1, queue<loc>());

    for (int i = 1; i <= P; i++) {
        cin >> speed[i];
    }

    for (int i = 0; i < N; i++) {
        string get; cin >> get;

        for (int j = 0; j < M; j++) {
            if (get[j] != '.') {
                if (get[j] == '#') {
                    graph[i][j] = -1;
                }
                else {
                    graph[i][j] = get[j] - '0';
                    que[get[j] - '0'].push({ i, j });
                }
            }
        }
    }

    bool updated = true;
    while (updated) {
        updated = false;

        for (int i = 1; i <= P; i++) {
            int moves = speed[i];
            while (moves-- && !que[i].empty()) {
                int que_size = que[i].size();
                bool res = bfs(i, que_size);
                if (updated == false) updated = res;
            }
        }
    }
    
    vector<int> ans(10, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] != -1) ans[graph[i][j]]++;
        }
    }
    for (int i = 1; i <= P; i++) cout << ans[i] << " ";
}

