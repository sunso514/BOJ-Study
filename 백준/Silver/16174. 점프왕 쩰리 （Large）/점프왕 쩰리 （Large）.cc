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


//int graph[1][1];
//vector<int> list(5000001);
//vector<vector<int>> vec;

int n, m;
int mapsize;
int graph[65][65];
bool found = false;


bool dfs(int x, int y) {
    if (x <= -1 || x >= mapsize || y <= -1 || y >= mapsize) return false;
    int size = 0;
    if (graph[x][y] == -1) {
        found = true;
        return true;
    }

    if (graph[x][y] != 0) {
        size = graph[x][y];
        graph[x][y] = 0;
        dfs(x + size, y);
        dfs(x, y + size);
    }
    if (found == true) {
        return true;
    }
    else return false;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> mapsize;

    for (int i = 0; i < mapsize; i++) {
        for (int j = 0; j < mapsize; j++) {
            int a;
            cin >> a;
            graph[i][j] = a;
        }
    }
    if (dfs(0, 0) == true) {
        cout << "HaruHaru";
    }
    else cout << "Hing";
    
}