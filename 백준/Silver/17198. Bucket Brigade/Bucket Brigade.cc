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


int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Location {
    int x, y, depth;
};

queue<Location> que;
vector<vector<int>> graph;

#define X l.x + dx[i]
#define Y l.y + dy[i]

void bfs() {
    Location l;
    while (!que.empty()) {
        l = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            if (X < 0 || Y < 0 || X >= 10|| Y >= 10) continue;
            if (graph[X][Y] == 0) {
                que.push({ X, Y, l.depth+1 });
                graph[X][Y] = 1;
            }
            if (graph[X][Y] == 2) {
                cout << l.depth;
                return;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    graph.resize(10, vector<int>(10));

    for (int i = 0; i < 10; i++) {
        string maps; cin >> maps;
        for (int j = 0; j < 10; j++) {
            if (maps[j] == '.') graph[i][j] = 0;
            else if (maps[j] == 'R') graph[i][j] = 1;
            else if (maps[j] == 'L') graph[i][j] = 2;
            else {
                que.push({ i, j, 0 });
            }
        }
    }
    bfs();
}