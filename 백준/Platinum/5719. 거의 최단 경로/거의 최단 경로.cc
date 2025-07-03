
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

struct tile {
    int weight, nxt_node;
};

struct cmp {
    bool operator()(info& a, info& b) {
        return a.weight > b.weight;
    }
};
// 지금 수정해야할 점
// 1. 2차원 격자로 바꿔서 다익스트라를 진행 ( 완성 )
// 2. prev 배열 만들기 ( 만약 다익스트라 진행 도중 같은 cost를 만나면 prev에 넣어주기 )
// 3. prev 싹다 역추적 하면서 값 INF로 변경하기

int dijkstra(int N, int start, int dest, vector<vector<int>> &graph, bool check) {
    vector<int> cost(N, INF);
    priority_queue<info, vector<info>, cmp> pq;

    vector<vector<int>> prev(N);

    pq.push({ start, 0 });
    cost[start] = 0;

    while (!pq.empty()) {
        info now = pq.top();
        pq.pop();

        for (int i = 0; i < N; i++) {
            if (graph[now.loc][i] == INF) continue;

            int nxt_w = graph[now.loc][i] + now.weight;

            if (cost[i] > nxt_w) {
                prev[i].clear();
                prev[i].push_back(now.loc);

                cost[i] = nxt_w;
                pq.push({ i, nxt_w });
            }
            else if (cost[i] == nxt_w) prev[i].push_back(now.loc);
        }
    }

    if (cost[dest] == INF) return -1; // 경로를 찾을 수 없음.

    if (check == false) return cost[dest];

    // 역추적 시작  first : 출발점, second : 도착점
    queue<int> que;
    que.push(dest);
    while (!que.empty()) {
        int now = que.front();
        que.pop();

        if (prev[now].empty()) continue;
        for (auto i : prev[now]) {
            graph[i][now] = INF;
            que.push(i);
        }
        prev[now].clear();
    }

    return cost[dest];
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        int N, M, start, end;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        cin >> start >> end;
       
        vector<vector<int>> graph(N, vector<int>(N, INF));

        for (int i = 0; i < M; i++) {
            int a, b, w;
            cin >> a >> b >> w; 
            graph[a][b] = w;
        }
        dijkstra(N, start, end, graph, true);
        cout << dijkstra(N, start, end, graph, false) << endl;
    }
}

