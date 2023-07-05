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


#define X dx[i]+loc.x
#define Y dy[i]+loc.y

struct Flot {
	int siz, id;
};

struct Location {
	int x, y;
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int N , M;
vector<vector<int>> graph;
vector<vector<bool>> visit;

vector<vector<Flot>> flots;

queue<Location> road_que;
queue<Location> wall;

void bfs(Location tmp, int flot_id) {
	Location loc;

	queue<Location> save_road;
	queue<Location> que;
	que.push(tmp);
	save_road.push(tmp);
	int count = 1;

	visit[tmp.x][tmp.y] = true;
	

	while (!que.empty()) {
		loc = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			if (X < 0 || Y < 0 || X >= N || Y >= M) continue;
			if (visit[X][Y] == true || graph[X][Y] == 1) continue;
			que.push({ X, Y });
			save_road.push({ X, Y });
			visit[X][Y] = true;
			count++;
		}
	}

	while (!save_road.empty()) {
		Location st = save_road.front();
		save_road.pop();
		flots[st.x][st.y] = { count, flot_id };
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	visit.resize(N, vector<bool>(M));
	graph.resize(N, vector<int>(M));

	flots.resize(N, vector<Flot>(M));

	// input
	for (int i = 0; i < N; i++) {
		string tmp_str;
		cin >> tmp_str;
		for (int j = 0; j < M; j++) {
			graph[i][j] = tmp_str[j] - '0';
			if (graph[i][j] == 0) road_que.push({ i, j });
		}
	}

	int q_siz = road_que.size();
	for (int i = 0; i < q_siz; i++) {
		Location tmp = road_que.front();
		road_que.pop();

		if (visit[tmp.x][tmp.y] == false) {
			bfs(tmp, i);
		}
	}

	/*
	cout << "Test : check Size of flots" << endl;
	FOR(i, N) {
		FOR(j, M) {
			cout << flots[i][j].siz;
		}
		cout << endl;
	}
	*/

	FOR(i, N) {
		FOR(j, M) {
			if (graph[i][j] == 0) cout << 0;
			else {
				vector<int> vec;
				int res = 1;

				FOR(dir, 4) {

					// 밖으로 나가면 제외
					if (i + dx[dir] < 0 || j + dy[dir] < 0 || i + dx[dir] >= N || j + dy[dir] >= M) continue;
					if (graph[i + dx[dir]][j + dy[dir]] == 1) continue;

					bool pass_id = true;
					for (int ids = 0; ids < vec.size(); ids++) {
						if (vec[ids] == flots[i + dx[dir]][j + dy[dir]].id) {
							pass_id = false;
							break;
						}
					}
					if (pass_id == true) {
						vec.push_back(flots[i + dx[dir]][j + dy[dir]].id);
						res += flots[i + dx[dir]][j + dy[dir]].siz;
					}
				}
				cout << res%10;
			}
		}
		cout << endl;
	}
}