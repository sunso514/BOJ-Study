
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
    int x, y;
};
#define X dx[i] + loc.x
#define Y dy[i] + loc.y


queue<Location> que;
vector<vector<int>> visit;
vector<vector<int>> graph;


int dx[4] = { -1 , 1, 0, 0, };
int dy[4] = { 0, 0, 1, -1 };

int N, M, K;

bool canSearch(int x, int y) {
    if (x >= 0 && y >= 0 && x < N && y < M) {
        if (!visit[x][y] && graph[x][y] == 0) return true;
    }
    return false;
}

int bfs() {
    Location loc;
    int count = 0;
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            if (canSearch(X, Y)) {
                count++;
                visit[X][Y] = true;
                que.push({ X, Y });
            }
        }
    }
    if (count == 0) count++;
    return count;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
       
    cin >> M >> N >> K;
    graph.resize(N, vector<int>(M));
    visit.resize(N, vector<int>(M));
    int tmx, tmy, tmpx, tmpy;
    for (int i = 0; i < K; i++) {
        cin >> tmx >> tmy >> tmpx >> tmpy;
        
        for (int j = tmx; j < tmpx; j++) 
            for (int k = tmy; k < tmpy; k++) graph[j][k] = 1;
    }

    vector<int> ans;
    int amount = 0;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            if (graph[i][j] == 0 && !visit[i][j]) {
                que.push({ i, j });
                amount++;
                ans.push_back(bfs());
            }

    sort(ans.begin(), ans.end());
    cout << amount << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}