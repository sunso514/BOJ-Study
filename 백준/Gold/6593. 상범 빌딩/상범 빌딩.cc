#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define test "test "
#define endl "\n"
using namespace std;

struct Location {
    int floor, x, y, depth;
};

#define X dx[i] + loc.x
#define Y dy[i] + loc.y
#define Z dz[i] + loc.floor

queue<Location> que;

int dz[6] = { -1, 1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { 0, 0, 0, 0, 1, -1 };


int flo, N, M;

bool checkRange(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return false;
    if (x >= N || y >= M || z >= flo) return false;
    return true;
}


void bfs(vector<vector<vector<int>>> gph) {
    Location loc;
    while (!que.empty()) {
        loc = que.front();
        que.pop();

        for (int i = 0; i < 6; i++) {
            if (!checkRange(X, Y, Z)) continue;
            if (gph[Z][X][Y] == 1) continue;
            if (gph[Z][X][Y] == 2) {
                cout << "Escaped in " << loc.depth + 1<< " minute(s)." << endl;
                return;
            }
            que.push({ Z, X, Y, loc.depth + 1 });
            gph[Z][X][Y] = 1; 
        }
    }
    cout << "Trapped!" << endl;
    return;
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    while (true) {
        cin >> flo >> N >> M;

        // 종료 조건
        if (flo == 0 && N == 0 && M == 0) break;

        // 초기화
        vector<vector<vector<int>>> graph(flo, vector<vector<int>>(N, vector<int>(M)));
        while (!que.empty()) que.pop();

        for (int i = 0; i < flo; i++) {
            string tm;
            for (int j = 0; j < N; j++) {
                cin >> tm;
                for (int k = 0; k < M; k++) {
                    if (tm[k] == 'S') {
                        que.push({ i, j, k, 0 });
                        graph[i][j][k] = 0;
                    }
                    if (tm[k] == '.') graph[i][j][k] = 0;
                    if (tm[k] == 'E') graph[i][j][k] = 2;
                    if (tm[k] == '#') graph[i][j][k] = 1;
                }
            }
        }
        bfs(graph);
    }
}