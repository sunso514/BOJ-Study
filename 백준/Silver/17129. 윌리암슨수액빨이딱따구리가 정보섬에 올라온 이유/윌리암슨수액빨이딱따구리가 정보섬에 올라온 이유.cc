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

int N, M;
vector<vector<int>> graph;

struct Location {
    int x, y, depth;
};

int dx[4] = { -1, 1, 0 , 0 };
int dy[4] = { 0, 0, 1, -1 };

queue<Location> que;
vector<vector<bool>> visit;

void BFS() {
    Location loc;
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int tmx = loc.x + dx[i];
            int tmy = loc.y + dy[i];
            if (tmx >= 0 && tmy >= 0 && tmx < N && tmy < M && !visit[tmx][tmy] && graph[tmx][tmy] != 1) {
                if (graph[tmx][tmy] != 0) {
                    //cout << tmx << " " << tmy << graph[tmx][tmy] << endl;
                    cout << "TAK" << endl << loc.depth + 1;
                    return;
                }
                que.push({ tmx, tmy, loc.depth + 1 });
                visit[tmx][tmy] = true;
                //cout << tmx << " " << tmy << endl;
            }
        }
    }
    cout << "NIE";
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    graph.resize(N + 1, vector<int>(M + 1));
    visit.resize(N + 1, vector<bool>(M + 1));
    string maps;
    for (int i = 0; i < N; i++) {
        cin >> maps;
        for (int j = 0; j < M; j++) {
            graph[i][j] = maps[j] - '0';
            if (graph[i][j] == 2) {
                que.push({ i, j, 0 });
                visit[i][j] = true;
            }
        }
    }
    BFS();
}