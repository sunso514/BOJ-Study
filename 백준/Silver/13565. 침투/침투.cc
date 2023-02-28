#include <iostream>
#include <algorithm>

#include <queue>
#include <vector>
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

bool BFS() {
    Location loc;

    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int tx = loc.x + dx[i];
            int ty = loc.y + dy[i];
            if (ty >= 0 && tx >= 0 && tx < N && ty < M && !visit[tx][ty] && graph[tx][ty] == 0) {
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    graph.resize(N, vector<int>(M));
    visit.resize(N, vector<bool>(M));

    string inp;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        for (int j = 0; j < M; j++) {
            graph[i][j] = inp[j] - '0'; 
            if (i == 0 && graph[i][j] == 0)  que.push({ i, j });
        }
    }

    if (BFS() == true) cout << "YES";
    else cout << "NO";

}