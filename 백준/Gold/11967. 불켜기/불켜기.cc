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


struct Location {
    int x, y;
};

vector<vector<bool>> graph;
vector<vector<bool>> visited;

vector<Location> switches[100][100];
queue<Location> que;
int N;
int ans = 1;


#define X loc.x + dx[i]
#define Y loc.y + dy[i]
#define SX tmp.x + dx[ck]
#define SY tmp.y + dy[ck]

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool checkCanGo(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) return false;
    if (visited[x][y] || graph[x][y] == 0) return false;
    return true;
}


void bfs() {
    Location loc;
    Location tmp;
    que.push({ 0, 0 });
    fill(visited.begin(), visited.end(), vector<bool>(N, 0));
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        while (graph[loc.x][loc.y] == 1 && !switches[loc.x][loc.y].empty()) {
            tmp = switches[loc.x][loc.y].back();
            switches[loc.x][loc.y].pop_back();
            if (!graph[tmp.x][tmp.y]) {
                ans++;
                graph[tmp.x][tmp.y] = 1;
                for (int ck = 0; ck < 4; ck++) {
                    if (SX < 0 || SY < 0 || SX >= N || SY >= N) continue;
                    if (visited[SX][SY]) {
                        que.push({ tmp.x, tmp.y });
                        visited[tmp.x][tmp.y] = true;
                        ck += 5;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            if (!checkCanGo(X, Y)) continue;
            que.push({ X, Y });
            visited[X][Y] = true;
        }
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    graph.resize(N, vector<bool>(N));
    visited.resize(N, vector<bool>(N));
    graph[0][0] = 1;
    visited[0][0] = true;
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        switches[a - 1][b - 1].push_back({ c - 1, d - 1 });
    }
    bfs();
    cout << ans;
}