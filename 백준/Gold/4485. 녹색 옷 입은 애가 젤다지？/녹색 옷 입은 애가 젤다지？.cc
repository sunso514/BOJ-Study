#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)



int V, E;

struct Location {
	int cost, x, y;
};

struct compare {
	bool operator()(const Location& l1, const Location& l2) {
		return l1.cost > l2.cost;
	}
};

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1 , -1 };

vector<vector<int>> costs(126, vector<int>(126));

const int INF = 1000000007;
vector<vector<int>> d(126, vector<int>(126, INF));

void dijkstra(int strx, int stry) {

	vector<Location> adj[126][126];
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			d[i][j] = INF;
		}
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int tm = 0; tm < 4; tm++) {
				if (i + dx[tm] < 1 || i + dx[tm] > V || j + dy[tm] < 1 || j + dy[tm] > V) continue;
				adj[i][j].push_back({ costs[i + dx[tm]][j + dy[tm]], i + dx[tm], j + dy[tm] });
			}
		}
	}

	d[strx][stry] = costs[1][1];

	priority_queue<Location, vector<Location>, compare> pq;

	pq.push({ d[strx][stry], strx, stry });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		for (auto next : adj[cur.x][cur.y]) {
			if (d[next.x][next.y] <= d[cur.x][cur.y]+next.cost) continue;
			d[next.x][next.y] = d[cur.x][cur.y] + next.cost;
			pq.push({ d[next.x][next.y], next.x, next.y });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int count = 1;
	while (true) {
		cin >> V;
		if (V == 0) return 0;
		int last = 0;
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				cin >> costs[i][j];
			}
		}

		dijkstra(1, 1);
		std::cout <<"Problem " << count << ": " << d[V][V] << endl;
		count++;
	}

}