#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int N, M, X;

struct Location {
	int index, cost;
};

struct compare {
	bool operator()(const Location& l1, const Location& l2) {
		return l1.cost > l2.cost;
	}
};

const int INF = 1000000007;
vector<int> d(1002, INF);
vector<int> res(1002, 0);
vector<Location> adj[1002];

void dijkstra(int str) {
	d.clear();
	d.resize(N + 1, INF);
	priority_queue<Location, vector<Location>, compare> pq;
	
	d[str] = 0;
	pq.push({ str, d[str] });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		for (auto nxt : adj[cur.index]) {
			if (d[cur.index] + nxt.cost > d[nxt.index]) continue;
			d[nxt.index] = d[cur.index] + nxt.cost;
			pq.push({ nxt.index, d[nxt.index] });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ b, cost });
	}


	for (int i = 1; i <= N; i++) {
		dijkstra(i);
		res[i] = d[X];
	}

	dijkstra(X);

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		res[i] += d[i];
		answer = max(answer, res[i]);
	}
	cout << answer;


}