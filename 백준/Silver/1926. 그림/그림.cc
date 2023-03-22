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
    int x; int y;
};


#define X dx[i] + loc.x
#define Y dy[i] + loc.y

vector<vector<int>> graph;
vector<vector<int>> visit;
queue<Location> que;

int dx[4] = { -1 , 1, 0, 0, };
int dy[4] = { 0, 0, 1, -1 };

int N, M;

int highest = 0;
int sizes = 0;

void bfs() {
    Location loc;
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            if (X >= 0 && Y >= 0 && X < N && Y < M) {
                if (!visit[X][Y] && graph[X][Y] == 1) {
                    sizes++;
                    visit[X][Y] = true;
                    que.push({ X,Y });
                }
            }
        }
    }
    if (highest < sizes) highest = sizes;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    graph.resize(N, vector<int>(M));
    visit.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
    int amount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visit[i][j] && graph[i][j] == 1) {
                sizes = 1;
                que.push({ i, j });
                visit[i][j] = true;
                bfs();
                amount++;
           }
        }
    }
    cout << amount << endl << highest;
}