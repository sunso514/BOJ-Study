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

#define MAX 105 // 최대 정점의 개수
#define INF 99999999

int user, gw;

vector<bool> check(MAX);
vector<vector<int>> graph(MAX, vector<int>(MAX));
vector<int> length(MAX);

//    vector<int> list(time);
//vector<int> list;
//vector<vector<int>> vec;

int bfs(int start) {
    queue<int> q;
    q.push(start);
    check[start] = true;
    while (!q.empty()) {
        int ch = q.front();
        q.pop();
        for (int j = 1; j <= user; j++) {
            if (graph[ch][j] == 1 && check[j] == false) {

                check[j] = true;
                q.push(j);
                length[j] = length[ch] + 1;
            }
        }
    }
    return 0;
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> user >> gw;

    int min = 99999989898989;
    int checknum = 0;

    for (int i = 0; i < gw; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int k = 1; k <= user; k++) {
        int bfsres = 0;
        bfs(k);
        for (int i = 1; i <= user; i++) {
            if (k != i) {
                bfsres += length[i];
            }
        }
        if (bfsres < min) {
            checknum = k;
            min = bfsres;
        }
        fill(check.begin(), check.end(), false);
        fill(length.begin(), length.end(), 0);
    }
    cout << checknum;
}