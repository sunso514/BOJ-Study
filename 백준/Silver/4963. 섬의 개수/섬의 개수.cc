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
    int x, y;
};

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};  
int dy[8] = { 1, 1, 1, 0 ,0, -1, -1, -1 };

queue<Location> que;
vector<vector<bool>> visit;

void BFS() {
    Location loc;
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int tmx = loc.x + dx[i];
            int tmy = loc.y + dy[i];
            if (tmx >= 0 && tmy >= 0 && tmx < N && tmy < M && !visit[tmx][tmy] && graph[tmx][tmy] == 1){
                que.push({ tmx, tmy });
                visit[tmx][tmy] = true;
            }
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    graph.resize(50, vector<int>(50, 0));
    visit.resize(50, vector<bool>(50, false));
    while(true){

        cin >> M >> N;
        if (M == 0 && N == 0) return 0;

        fill(visit.begin(), visit.end(), vector<bool>(50, false));
            
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++) cin >> graph[i][j];

        int island = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (graph[i][j] == 1 && !visit[i][j]) {
                    que.push({ i, j });
                    visit[i][j] = true;
                    BFS();
                    island++;
                }
            }
        }
        cout << island << endl;
    }
}