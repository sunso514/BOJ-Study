#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Loc {
    int x, y, depth;
};

vector<vector<int>> graph;
vector<vector<int>> visit;


queue<Loc> que;
int N, M;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int maxv = 0;


#define X tmp.x + dx[i]
#define Y tmp.y + dy[i]

void bfs() {
    Loc tmp;
    while (!que.empty()) {
        tmp = que.front();
        que.pop();


        for (int i = 0; i < 4; i++) {
            if (X < 0 || Y < 0 || X >= N || Y >= M) continue;
            if (visit[X][Y] == true || graph[X][Y] == 1) continue;
            maxv = max(maxv, tmp.depth + 1);
            que.push({ X, Y, tmp.depth + 1 });
            visit[X][Y] = true;
        }
    }
}

int main() {

    cin >> N >> M;

    graph.resize(N, vector<int>(M));
    visit.resize(N, vector<int>(M));
    string inp;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        for (int j = 0; j < M; j++) {
            graph[i][j] = (inp[j] == 'L') ? 0 : 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0) {
                fill(visit.begin(), visit.end(), vector<int>(M, 0));
                que.push({ i, j, 0 });
                visit[i][j] = true;
                bfs();
            }
        }
    }
    
    cout << maxv;
    return 0;
}