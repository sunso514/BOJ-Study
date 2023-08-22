#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, M;
int nowG = 0;

struct Location {
    int x, y;
};

int dx[4] = { 1, -1 , 0 ,0 };
int dy[4] = { 0, 0, 1, -1 };

vector<vector<vector<int>>> graph;
vector<vector<int>> visit;
queue<Location> que;
vector<Location> nonwater;

#define X x + dx[i]
#define Y y + dy[i]
#define nextG (nowG + 1) % 2


void dfs(int x, int y) {
    visit[x][y] = true;
    FOR(i, 4) {
        if (X < 0 || Y < 0 || X >= N || Y >= M) continue;
        if (graph[nowG][X][Y] != 0 && visit[X][Y] == false) dfs(X, Y);
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    graph.resize(2, vector<vector<int>>(N, vector<int>(M)));
    visit.resize(N, vector<int>(M));

    FOR(i, N) FOR(j, M){
        cin >> graph[0][i][j];
        if (graph[0][i][j] != 0) nonwater.push_back({ i, j });
    }
    
    int tcount = 0;
    while (true) {

        fill(visit.begin(), visit.end(), vector<int>(M));

        int count = 0;
        FOR(tc, nonwater.size()) {
            int x = nonwater[tc].x;
            int y = nonwater[tc].y;
            if (!visit[x][y] && graph[nowG][x][y] != 0) {
                dfs(x, y);
                
                count++;
            }
        }

        if (count == 0) {
            cout << 0;
            return 0;
        }
        if (count >= 2) {
            cout << tcount;
            return 0;
        }


        FOR(x, N) FOR(y, M) {
            graph[nextG][x][y] = 0;
            if (graph[nowG][x][y] == 0) continue;

            int val = 0;
            FOR(i, 4) {
                if (X < 0 || Y < 0 || X >= N || Y >= M) continue;
                if (graph[nowG][X][Y] == 0) val++;
            }

            graph[nextG][x][y] = max(0, graph[nowG][x][y] - val);
        }

        nowG = nextG;
        tcount++;
    }
}