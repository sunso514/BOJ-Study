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
vector<bool> check(1000000001);
//vector<vector<int>> vec;

struct Loc{
    long long x, depth;
};


int bfs(long long first, long long subin) {
    queue<Loc> que;

    que.push({ first, 1 }); // 노드 
    //check[first] = true; // 첫 노드 방문처리
    bool checksuc = false;
    Loc loc; // 구조체 불러오기
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        

        if (loc.x == subin) {
            checksuc = true;
            break;
        }
        loc.depth++;
        if (loc.x < subin && loc.x * 10 + 1 <= subin && !check[loc.x * 10 + 1]) {
            check[loc.x * 10 + 1] = true;
            que.push({ loc.x * 10 + 1, loc.depth });
        }
        if (loc.x < subin && loc.x*2 <= subin && !check[loc.x * 2]) {
            check[loc.x * 2] = true;
            que.push({ loc.x * 2, loc.depth });
            
        }
    
    }
    if (checksuc == true){
        return loc.depth;
    }
    else {
        return -1;
    }
    
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;

    cout << bfs(n, m);
    
}