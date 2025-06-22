
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <deque>
#include <set>
#include <tuple>
#include <iomanip>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)
#define INF 1000000009

using namespace std;

struct info {
    int loc, weight;
};
struct cmp {
    bool operator()(info& a, info& b) {
        return a.weight > b.weight; 
    }
};

vector<int> dijkstra(vector<vector<info>> route, int N, int M, int start) {
    vector<int> cost(N + 1, INF); // 방문 체크
    vector<int> pri_route(N + 1, -1);
    priority_queue<info, vector<info>, cmp> que;
    que.push({ start, 0 });

    cost[start] = 0;


    while (!que.empty()) {
        info now = que.top();
        que.pop();
        
        if (now.weight > cost[now.loc]) continue; // 이미 확인한 간선 패스

        for (info next : route[now.loc]) {
            int next_node = next.loc;

            int next_weight = now.weight + next.weight;

            if (cost[next_node] > next_weight) {
                cost[next_node] = next_weight;
                pri_route[next_node] = now.loc;
                que.push({ next_node, next_weight });
            }
        }
    }
    return cost;
}


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    

    // 문제 정리
    // 피추격자는 최단 경로로 이동한다.
    // 우리는 최단 경로의 일부 중 하나를 안다.
    // 주어진 목적지 후보들 중 불가능한 경우 제외한 목적지 출력

    // 접근
    // 목적지 후보로 다익스트라를 보내고 
    // 만약 g => h 혹은 h => g를 건들이지 않을 경우 ( g/h 를 도착할 때 다음 노드가 h/g 라면 )
    // false로 후보에서 제외한다.

    int T; // Test Case
    cin >> T;

    while (T--) {
        int N, M, T;  // 교차로/도로/목적지 후보 개수
        cin >> N >> M >> T;

        int S, G, H; // 출발지, g=>h 도로
        cin >> S >> G >> H;
        
        int gh_dist;
        vector<vector<info>> route(N+1);
        for(int i = 0; i < M; i++){
            int a, b, d; cin >> a >> b >> d;
            if ((a == G && b == H) || (a == H && b == G)) {
                gh_dist = d;
            }
            route[a].push_back({ b, d }); // 길 잇기
            route[b].push_back({ a, d });
        }

        vector<int> destinations;
        for (int i = 0; i < T; i++) {
            int a; cin >> a;
            destinations.push_back(a);
        }
        sort(destinations.begin(), destinations.end());

        vector<int> sCost = dijkstra(route, N, M, S);
        vector<int> gCost = dijkstra(route, N, M, G);
        vector<int> hCost = dijkstra(route, N, M, H);

        for (auto dest : destinations) {
            // s => g => h => 목적지
            if (sCost[dest] == sCost[G] + gh_dist + hCost[dest]) {
                cout << dest << " ";
                continue;
            }
            // s => h => g => 목적지
            if (sCost[dest] == sCost[H] + gh_dist + gCost[dest]) {
                cout << dest << " ";
                continue;
            }
        }

        cout << "\n";
    }

}

