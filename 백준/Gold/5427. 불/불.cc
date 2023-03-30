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
    int x, y, depth;
};

#define X dx[i] + loc.x
#define Y dy[i] + loc.y
#define FX dx[i] + fire.x
#define FY dy[i] + fire.y

vector<vector<int>> graph(1002, vector<int>(1002, 0));
vector<vector<int>> firegraph(1002, vector<int>(1002, -1));
queue<Location> que;
queue<Location> Fire;

int dx[4] = { -1 , 1, 0, 0, };
int dy[4] = { 0, 0, 1, -1 };

int N, M;

int bfs() {
    Location loc;
    Location fire;


    while (!Fire.empty()) {
        fire = Fire.front();
        Fire.pop();
        for (int i = 0; i < 4; i++) {
            if (FX < 0 || FY < 0 || FX >= N || FY >= M) continue;
            if (graph[FX][FY] != 0 && graph[FX][FY] != 3) continue;
            firegraph[FX][FY] = fire.depth + 1;
            graph[FX][FY] = 2;
            Fire.push({ FX, FY, fire.depth + 1 });
        }
    }
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            if (X < 0 || Y < 0 || X >= N || Y >= M) continue;
            if (graph[X][Y] != 0 && graph[X][Y] != 2) continue;
            if (firegraph[X][Y] > loc.depth + 1 || firegraph[X][Y] == -1) {
                if (X == 0 || Y == 0 || X == N - 1 || Y == M - 1) {
                    return loc.depth + 2;
                }
                graph[X][Y] = 1;
                que.push({ X,Y, loc.depth + 1 });
            }
 
        }
    }
    return -1;
    
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int tm; cin >> tm;
    for (int t = 0; t < tm; t++) {
        cin >> M >> N;

        while (!que.empty()) que.pop();
        while (!Fire.empty()) Fire.pop();


        string get;
        bool tete = false;
        for (int i = 0; i < N; i++) {
            cin >> get;
            for (int j = 0; j < M; j++) {
                firegraph[i][j] = -1;
                if (get[j] == '#') graph[i][j] = 1;
                if (get[j] == '.') graph[i][j] = 0;
                if (get[j] == '@') {
                    if (i == 0 || j == 0 || i == N - 1 || j == M - 1) tete = true;
                    graph[i][j] = 0;
                    que.push({ i, j, 0 });
                }
                if (get[j] == '*') {
                    graph[i][j] = 2;
                    Fire.push({ i, j, 0 });
                    firegraph[i][j] = 0;
                }
            }
        }
        if (tete) {
            cout << 1 << endl;
            continue;
        }
        int res = bfs();
        if (res == -1) cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;
    }
}