
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


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<info>> graph(N+1);

    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
    }
    
    // 다익스트라를 여따가 그냥 적어야할듯

    vector<priority_queue<int>> visit(N + 1); // 최대 힙
    priority_queue<info, vector<info>, cmp> pq;
    
    pq.push({ 1, 0 });
    visit[1].push(0);
    while (!pq.empty()) {
        info now = pq.top();
        pq.pop();

        for (info next : graph[now.loc]) {
            int nxt_n = next.loc;
            int nxt_w = next.weight + now.weight;

            if (visit[nxt_n].size() < K || visit[nxt_n].top() > nxt_w) {
                visit[nxt_n].push(nxt_w);
                if (visit[nxt_n].size() > K) visit[nxt_n].pop();
                pq.push({ nxt_n, nxt_w });
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (visit[i].size() < K) cout << -1 << endl;
        else cout << visit[i].top() << endl;
    }
}

