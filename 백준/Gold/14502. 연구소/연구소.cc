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
using namespace std;

struct Location {
    int x, y;
};

vector<vector<int>> graph;
vector<vector<int>> visit;
queue<Location> que;
vector<Location> gns;

int N, M, max, safe;

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


bool checkVoid(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) return false;
    return true;
}

int bfs() {
    Location loc;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = false;
            if (graph[i][j] == 2) que.push({ i, j });
        }
    }
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            if (checkVoid(X, Y)) {
                if (graph[X][Y] == 0 && visit[X][Y] != -1 && !visit[X][Y]) {
                    que.push({ X, Y });
                    visit[X][Y] = true;
                    count++;
                }
            }
        }
    }
    return safe-count-3;

}


int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    graph.resize(N, vector<int>(M));
    visit.resize(N, vector<int>(M));
    safe = M * N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) gns.push_back({ i, j });
            if (graph[i][j] == 1) safe--;
            if (graph[i][j] == 2) safe--;
        }
    }
    
    int max = 0;
    for (int i = 0; i < gns.size()-2; i++) {
        for (int j = i + 1; j < gns.size()-1; j++) {
            for (int k = j + 1; k < gns.size(); k++) {
                graph[gns[i].x][gns[i].y] = 1;
                graph[gns[j].x][gns[j].y] = 1;
                graph[gns[k].x][gns[k].y] = 1;
                int tmp = bfs();
                graph[gns[i].x][gns[i].y] = 0;
                graph[gns[j].x][gns[j].y] = 0;
                graph[gns[k].x][gns[k].y] = 0;
                if (tmp > max) max = tmp;
            }
        }
    }
    cout << max;
}