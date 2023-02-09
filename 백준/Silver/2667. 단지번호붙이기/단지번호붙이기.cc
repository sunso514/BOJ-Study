#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, danjiamount = 0;
vector<vector<int>> graph; // 노드
int houseamount[700];


bool dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) return false;
    if (graph[x][y] == 1) {        
        graph[x][y] = 0; // 방문 처리
        houseamount[danjiamount]++;
        dfs(x - 1, y);
        dfs(x, y - 1);
        dfs(x + 1, y);
        dfs(x, y + 1);
        return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    graph.resize(N+1, vector<int>(N+1, 0));


    for (int i = 0; i < N; i++) {
        string getmap;
        cin >> getmap;
        for (int j = 0; j < N; j++) { // 맵 저장
            graph[i][j] = getmap[j] - '0';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 현재 위치에서 DFS 수행
            if (dfs(i, j)) {
                danjiamount += 1;
            }
        }
    }
    sort(houseamount, houseamount+danjiamount);
    cout << danjiamount << "\n";
    for (int i = 0; i < danjiamount; i++) {
        cout << houseamount[i] << "\n";
    }
}