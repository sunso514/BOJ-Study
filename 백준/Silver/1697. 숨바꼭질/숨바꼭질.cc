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



int n, m, streak;

//int graph[1][1];
vector<bool> check(100001);
//vector<vector<int>> vec;

struct Loc{
    int x, depth;
};


int bfs(int first, int subin) {
    queue<Loc> que;
  
    que.push({ first, 0 }); // 노드 
    check[first] = true; // 첫 노드 방문처리

   
    Loc loc; // 구조체 불러오기
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        if (loc.x == subin) break;
        loc.depth++;

        if (loc.x + 1 <= 100000 && !check[loc.x + 1]) {
            que.push({ loc.x + 1, loc.depth });
            check[loc.x+1] = true;
        }

        if (loc.x -1 >= 0 && !check[loc.x - 1]) {
            que.push({ loc.x - 1, loc.depth });
            check[loc.x-1] = true;
        }

        if (loc.x * 2 <= 100000 && !check[loc.x *2]) {
            que.push({ loc.x * 2, loc.depth });
            check[loc.x*2] = true;
        }
    }
    return loc.depth;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;

    cout << bfs(n, m);
    
}