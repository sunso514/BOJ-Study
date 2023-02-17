#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#define test "test "
using namespace std;
const int INF = 999999999;



typedef pair<int, int> pr;

//vector<int> list;

vector<int> dijkstra(int vertex, int start, vector<vector<pr>>& graph) {

    vector<int> dijk(vertex + 1, INF);
    priority_queue<pr, vector<pr>, greater<pr>> pq; // x : 시작점으로부터 거리 y : 정점

    //시작 위치 초기화
    dijk[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        pr e = pq.top();
        pq.pop();

        if (e.first > dijk[e.second]) { // 이미 확인한 정점
            continue;
        }
        for (pr i : graph[e.second]) {
            int nd = i.first;
            int next_w = e.first + i.second;

            if (dijk[nd] > next_w) {
                dijk[nd] = next_w;
                pq.push({ next_w, nd });
            }
        }
        
    }
    return dijk;
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int vertex, edge, start, u, v, weight;

    cin >> vertex >> edge >> start;
    vector<vector<pr>> graph(vertex + 1, vector<pr>(0));

    
    for (int i = 0; i < edge; i++) {
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
    }

    vector<int> res = dijkstra(vertex, start, graph);

    for (int i = 1; i <= vertex; i++) {
        if (res[i] == INF)
            cout << "INF";
        else cout << res[i];
        cout << endl;
    }

}