#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define X loc.x + dx[i] * j
#define Y loc.y + dy[i] * j

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct Location
{
	int x, y, dir, depth;
};

int N, M, eX, eY, eD, sX, sY, sD;

vector<vector<int>> graph;
vector<vector<int>> visit;
queue<Location> que;

int bfs() {
	Location loc;
	int minv = 100000000;
	while (!que.empty()) {
		loc = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (X < 0 || Y < 0 || X >= N || Y >= M) break;
				if (graph[X][Y] == 1) break;

				int dep = 0;
				if (loc.dir == i) dep = 0;
				else if ((loc.dir + 1) % 4 == i || (loc.dir + 3) % 4 == i) dep = 1;
				else dep = 2;
				dep += (j == 0) ? 0 : 1;

				if (X == eX && Y == eY) {
					visit[X][Y] = loc.depth + dep;
					if (X == eX && Y == eY) {
						int ans = visit[eX][eY];
						if (i == eD) ans += 0;
						else if ((i + 1) % 4 == eD || (i + 3) % 4 == eD) ans++;
						else ans += 2;
						minv = min(minv,ans);
					}
				}
				else if (visit[X][Y] == 1000000 || visit[X][Y] > loc.depth + dep) {
					visit[X][Y] = loc.depth + dep;
					que.push({ X, Y, i, loc.depth + dep });
				}
			}
		}
	}
	return minv;
}


int main() {
	cin >> N >> M;


	graph.resize(N, vector<int>(M));
	visit.resize(N, vector<int>(M, 1000000));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	cin >> sX >> sY >> sD >> eX >> eY >> eD;
	sX--; sY--; eX--; eY--; sD--; eD--;

	if (sD == 1) sD = 2;
	else if (sD == 2) sD = 1;
	if (eD == 1) eD = 2;
	else if (eD == 2) eD = 1;

	que.push({ sX, sY, sD, 0 });
	cout << bfs();
	
}
