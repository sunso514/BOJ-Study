#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

using namespace std;

int R, C;

struct Location {
    int x, y, time;
};

vector<string> grid;
vector<vector<int>> visit;
vector<vector<int>> graph;

queue<Location> que;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(bool water) {
    Location loc;

    while (!que.empty()) {
        loc = que.front();
        que.pop();
        
        if (water == true) {
            graph[loc.x][loc.y] = loc.time;
            for (int i = 0; i < 4; i++) {
                if (X < 0 || Y < 0 || X >= R || Y >= C) continue;
                if (!visit[X][Y] && grid[X][Y] == '.') {
                    que.push({ X, Y, loc.time + 1 });
                    visit[X][Y] = true;
                }
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                if (X < 0 || Y < 0 || X >= R || Y >= C) continue;
                if (!visit[X][Y] && grid[X][Y] == '.' && graph[X][Y] > loc.time+1) {
                    que.push({ X, Y, loc.time + 1 });
                    visit[X][Y] = true;
                }
                if (grid[X][Y] == 'D') {
                    cout << loc.time + 1;
                    return;
                }
            }
        }
    }
    if (water == false) cout << "KAKTUS";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> R >> C;

    graph.resize(R, vector<int>(C, 20000));
    visit.resize(R, vector<int>(C));

    // 맵 받아오기
    for (int i = 0; i < R; i++) {
        string gmp;
        cin >> gmp;
        grid.push_back(gmp);
    }
    

    // 물 확산 bfs
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '*') {
                que.push({ i, j, 0 });
            }
        }
    }
    if (!que.empty()) bfs(true);

    visit.clear();
    visit.resize(R, vector<int>(C));
    
    // 집으로 가는 bfs
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'S') {
                que.push({ i, j, 0 });
                break;
            }
        }
    }
    bfs(false);
}