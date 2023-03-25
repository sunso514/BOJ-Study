#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Location {
    int x, y, depth;
};

#define X dx[i] + loc.x
#define Y dy[i] + loc.y
#define FX dx[i] + fire.x
#define FY dy[i] + fire.y

vector<vector<int>> graph;
vector<vector<int>> firegraph;
queue<Location> que;
queue<Location> Fire;

int dx[4] = { -1 , 1, 0, 0, };
int dy[4] = { 0, 0, 1, -1 };

int N, M;

void bfs() {
    Location loc;
    Location fire;


    while (!Fire.empty()) {
        fire = Fire.front();
        Fire.pop();
        for (int i = 0; i < 4; i++) {
            if (FX >= 0 && FY >= 0 && FX < N && FY < M) {
                if (graph[FX][FY] == 0) {
                    if (FX == 0 || FY == 0 || FX == N - 1 || FY == M - 1) firegraph[FX][FY] = fire.depth + 2;
                    graph[FX][FY] = 2;
                    Fire.push({ FX, FY, fire.depth + 1 });
                }
            }
        }
    }
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            if (X >= 0 && Y >= 0 && X < N && Y < M) {
                if (graph[X][Y] == 0 || graph[X][Y] == 2) {
                    if (X == 0 || Y == 0 || X == N - 1 || Y == M - 1) {
                        if (firegraph[X][Y] == -1) {
                            cout << loc.depth + 2;
                            return;
                        }
                        else if (firegraph[X][Y] > loc.depth + 2) {
                            cout << loc.depth + 2;
                            return;
                        }
                    }
                    graph[X][Y] = 1;
                    que.push({ X,Y, loc.depth + 1 });
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    graph.resize(N, vector<int>(M));
    firegraph.resize(N, vector<int>(M, -1));

    string get;
    for (int i = 0; i < N; i++) {
        cin >> get;
        for (int j = 0; j < M; j++) {
            if (get[j] == '#') graph[i][j] = 1;
            if (get[j] == '.') graph[i][j] = 0;
            if (get[j] == 'J') {
                graph[i][j] = 3;
                if (i == N - 1 || j == M - 1 || i == 0 || j == 0) {
                    cout << 1;
                    return 0;
                }
                que.push({ i, j, 0 });
            }
            if (get[j] == 'F') {
                graph[i][j] = 2;
                Fire.push({ i, j, 0 });
                firegraph[i][j] = 0;
            }
        }
    }
    bfs();
}