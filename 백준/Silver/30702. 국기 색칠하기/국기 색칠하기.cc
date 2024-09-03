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

#include <bitset>

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;


struct location {
	int x, y;
};

int N, M;

vector<string> basic;
vector<string> goal;

vector<vector<int>> visit;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

#define X tmp.x + dx[i]
#define Y tmp.y + dy[i]


bool bfs(int x, int y, char s, char g) {
	queue<location> que;
	visit[x][y] = true;
	que.push({ x, y });
	while (!que.empty()) {
		location tmp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			//cout << X << " " << Y << " " << basic[0].size() << " " << goal[0].size() << " " << visit[0].size() <<  endl;
			if (X < 0 || Y < 0 || X >= N || Y >= M) continue;
			if (visit[X][Y] == true || s != basic[X][Y]) continue;
			if (goal[X][Y] != g) {
				return false;
			}
			visit[X][Y] = true;
			que.push({ X, Y });
		}
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	goal.resize(N);
	basic.resize(N);

	visit.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		cin >> basic[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> goal[i];
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == true) continue;
			if (bfs(i, j, basic[i][j], goal[i][j]) == false) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";

}