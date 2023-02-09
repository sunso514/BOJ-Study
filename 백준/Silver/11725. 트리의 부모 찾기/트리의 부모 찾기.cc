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

//#define MAX 1000002 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;

#define MAX 100001
vector<int> v[MAX];
int times;
int gp[MAX];
bool check[MAX];


void dfs(int now) {
    check[now] = true;
    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        if (!check[next]) {
            gp[next] = now;
            dfs(next);
        }
    }
}

int main() {
    cin >> times;
    for (int i = 0; i < times; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);



    for (int i = 2; i <= times; i++) {
        cout << gp[i] << "\n";
    }
}