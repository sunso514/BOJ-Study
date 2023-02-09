#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>

using namespace std;
//    vector<int> list(time);
//vector<int> list;

// 크기 변수 설정
int n, m;

//방향 설정 
int mx[] = { -1, 1, 0, 0 };
int my[] = { 0, 0, -1, 1 };

// 미로 그래프 설정
int nodes[101][101];

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });

    //큐가 빌 때까지 반복시킨다.
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // (x , y) 에서 4가지 방향 다 돌린다.
        for (int i = 0; i < 4; i++) {
            int nowx = x + mx[i];
            int nowy = y + my[i];
            //공간을 벗어나면 무시한다.
            if (nowx < 0 || nowy < 0 || nowx >= n || nowy >= m) continue;
            //벽은 무시한다.
            if (nodes[nowx][nowy] == 0) continue;
            // 처음 방문하는 곳인지 체크
            if (nodes[nowx][nowy] == 1) {
                nodes[nowx][nowy] = nodes[x][y]+1;
                q.push({ nowx, nowy });
            }
        }
    }
    return nodes[n - 1][m - 1];
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &nodes[i][j]);
        }
    }
    cout << bfs(0, 0) << "\n";

}