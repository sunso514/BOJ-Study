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
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)



int V, E;

struct Location {
	int cost, num;
};

struct compare {
	bool operator()(const Location& l1, const Location& l2) {
		return l1.cost > l2.cost;
		if (l1.num == l2.num) {
			return l1.cost > l2.cost;
		}
		else return l1.num > l2.num;
	}
};

vector<Location> adj[803];
const int INF = 1000000007;
vector<int> d(803, INF);

void dijkstra(int str) {
	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}

	d[str] = 0;

	priority_queue<Location, vector<Location>, compare> pq;

	pq.push({ d[str], str });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		for (auto next : adj[cur.num]) {
			if (d[next.num] <= d[cur.num]+next.cost) continue;
			d[next.num] = d[cur.num] + next.cost;
			pq.push({ d[next.num], next.num });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
	int first, second;
	cin >> first >> second;
	long long f_s, f_1, f_V;
	long long s_1, s_V;
	// 양방향 이므로 first 정점에서 각 간선끼리 거리를 구한다.
	dijkstra(first);
	f_s = d[second];
	f_1 = d[1];
	f_V = d[V];
	
	dijkstra(second);
	s_1 = d[1];
	s_V = d[V];
	//cout << f_s << " " << f_1 << " " << f_V << " " << s_1 << " " << s_V << endl;
	long long res = min(f_1 + f_s + s_V, s_1 + f_s + f_V);
	
	if (res >= INF) cout << -1;
	else cout << res;
}