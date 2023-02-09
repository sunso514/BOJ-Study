#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int>> graph;
int counts = 0;
int N, M, casenum = 0;

int dfs(int x, int y, int id) {
    if (x < 0 || y < 0 || x >= M || y >= N) return 0;
    if (graph[x][y] == id) {
        counts++;
        graph[x][y] = 0;
        dfs(x - 1, y, id);
        dfs(x, y - 1, id);
        dfs(x + 1, y, id);
        dfs(x, y + 1, id);
        return counts;
    }
    return 0;
}


int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    graph.resize(M, vector<int>(N, 0));
    vector<int> res(2, 0);
    
    string army;
    for (int i = 0; i < M; i++) {
        cin >> army;
        for (int j = 0; j < N; j++) {
            if (army[j] == 'W') graph[i][j] = 1;
            else graph[i][j] = 2;
        }
    }
    int a = 0;
    for (int i = 0; i < M; i++) 
        for (int j = 0; j < N; j++) {
            counts = 0;
            int check = graph[i][j];
            if (check != 0) a = dfs(i, j, graph[i][j]);
            if (a > 0) {
                if (check == 1) res[0] += a * a;
                else if (check == 2) res[1] += a * a;
            }
        }
    cout << res[0] << " " << res[1];
}