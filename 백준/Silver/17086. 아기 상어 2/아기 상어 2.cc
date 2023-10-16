#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

struct Location {
	int x, y, time;
};

#define X dx[i] + loc.x
#define Y dy[i] + loc.y

int N, M;

queue<Location> que;
vector<vector<int>> visit;
vector<vector<int>> graph;

int dx[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int dy[8] = { 0, -1, 1, 0, 1, -1, 1, -1};


void bfs() {
	int ans = 0;
	Location loc;

	while (!que.empty()) {
		loc = que.front();
		que.pop();
		FOR(i, 8) {
			if (X < 0 || Y < 0 || X >= N || Y >= M) continue;
			if (visit[X][Y] == true || graph[X][Y] == 1) continue;
			visit[X][Y] = true;
			que.push({ X, Y, loc.time + 1 });
			ans = max(ans, loc.time + 1);
		}
	}
	cout << ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	graph.resize(N, vector<int>(M));
	visit.resize(N, vector<int>(M));

	FOR(i, N) FOR(j, M) {
		cin >> graph[i][j];
		if (graph[i][j] == 1) que.push({ i, j, 0 });
	}
	bfs();
}