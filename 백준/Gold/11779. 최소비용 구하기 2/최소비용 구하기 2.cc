#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl "\n"

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
int pre[1002];
vector<Location> adj[1002];

void dijkstra(int str) {
	priority_queue<Location, vector<Location>, compare> pq;
	
	d[str] = 0;
	pq.push({ str, d[str] });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (d[cur.index] != cur.cost) continue;
		for (auto nxt : adj[cur.index]) {
			if (d[nxt.index] <= d[cur.index] + nxt.cost) continue;
			d[nxt.index] = d[cur.index] + nxt.cost;
			pq.push({ nxt.index, d[nxt.index] });
			pre[nxt.index] = cur.index;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		adj[s].push_back({ e, cost });
	}

	int start, end; cin >> start >> end;
	dijkstra(start);


	int current = end;

	vector<int> path;
	while (current) {
		path.push_back(current);
		current = pre[current];
	}
	reverse(path.begin(), path.end());
	cout << d[end] << endl << path.size() << endl;
	for (auto i : path) cout << i << " ";

}