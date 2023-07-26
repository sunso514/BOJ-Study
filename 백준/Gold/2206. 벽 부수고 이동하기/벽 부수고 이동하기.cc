#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };

struct Location {
	int x, y, broke, turn;
	bool day;
};

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

int N, M, K;
vector<vector<int>> graph;
vector<vector<vector<int>>> visit;
queue<Location> que;

void bfs() {
	Location loc;

	while (!que.empty()) {
		loc = que.front(); que.pop();
		if (loc.x == N - 1 && loc.y == M - 1) {
			cout << loc.turn;
			return;
		}
		FOR(i, 4) {
			if (X < 0 || Y < 0 || X >= N || Y >= M) continue;
			

			if (graph[X][Y] == 1) {
				if (loc.broke >= K) continue;
				if (visit[loc.broke + 1][X][Y] == true) continue;
				visit[loc.broke+1][X][Y] = true;
				que.push({ X, Y, loc.broke + 1, loc.turn + 1, false });
			}
			else {
				if (visit[loc.broke][X][Y] == true) continue;
				visit[loc.broke][X][Y] = true;
				que.push({ X, Y, loc.broke, loc.turn + 1, false });
			}
		}
	}
	cout << -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
    K = 1;
	graph.resize(N, vector<int>(M));
	visit.resize(11, vector<vector<int>>(N, vector<int>(M)));

	FOR(i, N) {
		string mapinf;
		cin >> mapinf;
		FOR(j, M) graph[i][j] = mapinf[j] - '0';
	}
	que.push({ 0, 0, 0, 1, true });
	bfs();
} 