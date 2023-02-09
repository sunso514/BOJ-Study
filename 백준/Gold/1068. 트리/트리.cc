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

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;

int times;
int startnode = 0;
int ct = 0;
vector<bool> check;
vector<vector<int>> nodes;
vector<int> checkbumo;

void dfs(int start) {
    check[start] = true;
    if (nodes[start].size() == 0) {
        ct++;
        return;
    }
   // cout << "순회중 :" << start << endl;
   // cout << nodes[start].size() << endl;
    
    for (int i = 0; i < nodes[start].size(); i++) {
        int next = nodes[start][i];
        
        if (!check[next]) {
            dfs(next);
        }
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> times;
    checkbumo.resize(times);
    check.resize(times);
    nodes.resize(times, vector<int>());
    int a;
    for (int i = 0; i < times; i++) {
        cin >> a;
        if (a != -1) {
            nodes[a].push_back(i);
            checkbumo[i] = a; // i 번쨰 노드의 부모는 a
        }
        else {
            startnode = i;
        }
    }
    int erase;
    cin >> erase;
    if (erase == startnode) {
        cout << 0;
        return 0;
    }
    int lc = 0;
    for (auto i : nodes[checkbumo[erase]]) { // 부모 노드 모두 루프
        if (erase == i) {
            nodes[checkbumo[erase]].erase(nodes[checkbumo[erase]].begin() + lc);
            /*if (nodes[checkbumo[erase]].size() == 0) {
                cout << 0;
                return 0;
            }*/
            break;
        }
        lc++;
    }
    dfs(startnode);
    cout << ct;
}