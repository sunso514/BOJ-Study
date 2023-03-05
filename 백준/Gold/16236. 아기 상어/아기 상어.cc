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

#define tx loc.x + dx[i]
#define ty loc.y + dy[i]

using namespace std;


struct Location {
    int x, y, depth;
};


int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<vector<int>> graph;
vector<vector<bool>> visit;
queue<Location> que;


int N;
int eattime = 0, sh_exp = 0, sh_size = 2;

bool bfs() {

    Location loc;
    int min = 999999999; // 최단경로
    int g_x = 0; // 먹을 물고기 좌표 저장
    int g_y = 0;

    while (!que.empty()) {
        loc = que.front();
        que.pop();
        if (loc.depth > min) continue; // 최단 거리가 아니므로 컨티뉴

        for (int i = 0; i < 4; i++) {

            if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue; // 방문 불가능한 좌표 컨티뉴
            if (visit[tx][ty] == true || sh_size < graph[tx][ty]) continue;

            if (graph[tx][ty] != 0 && sh_size > graph[tx][ty]) {
                int temp = loc.depth + 1; // 걸린 시간

                if (temp < min) { // 먹을 수 있는 물고기 최단경로 발견
                    min = temp;
                    g_x = tx;  g_y = ty;
                }
                else if (temp == min) { // 먹을 수 있는 물고기 여러마리일 경우
                    if (tx < g_x) {
                        g_x = tx;
                        g_y = ty;
                    }
                    else if (tx == g_x && ty < g_y) g_y = ty;
                    
                }
            }
            else {
                que.push({ tx, ty, loc.depth + 1 });
                visit[tx][ty] = true;
            }
        }
    }
    if (min < 999999998) {
        sh_exp += 1;
        if (sh_exp == sh_size) {
            sh_size++;
            sh_exp = 0;
        }
        eattime += min;
        fill(visit.begin(), visit.end(), vector<bool>(N));
        graph[g_x][g_y] = 0;
        visit[g_x][g_y] = true;
        while (!que.empty()) que.pop();
        que.push({ g_x, g_y, 0 });
        return true;
    }
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //cout << graph[i][j];
            }
            //cout <<endl;
        }
        return false;
    }
}


int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    graph.resize(N, vector<int>(N));
    visit.resize(N, vector<bool>(N));
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 9) {
                que.push({ i, j, 0 });
                graph[i][j] = 0;
                visit[i][j] = true;
            }
        }
    
    while (1) {
        if (bfs() == false) {
            cout << eattime;
            return 0;
        }
    }

}