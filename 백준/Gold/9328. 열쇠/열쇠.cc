#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#include <bitset>

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N, M;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

#define X dx[i] + loc.x
#define Y dy[i] + loc.y

struct Location {
	int x, y;
};

int bfs(vector<vector<char>> &graph, vector<bool> &key) {
	int ans = 0;
	vector<vector<bool>> visit(N + 2, vector<bool>(M + 2));

	queue<Location> que;
	queue<Location> tmp;
	que.push({ 0, 0 });

	// 변화가 있는지 확인 
	while (true) {

		bool check = true;
		while (!que.empty()) {
			Location loc;
			loc = que.front();
			que.pop();
            
			for (int i = 0; i < 4; i++) {
				if (X < 0 || Y < 0 || X >= N + 2 || Y >= M + 2) continue;
				if (graph[X][Y] == '*' || visit[X][Y] == true) continue;
				if ((graph[X][Y] >= 'A' && graph[X][Y] <= 'Z')) {
					if (key[graph[X][Y] - 'A'] == false) {
						tmp.push({ loc.x, loc.y });
						visit[loc.x][loc.y] = false;
						graph[loc.x][loc.y] = ',';
						continue;
					}
					graph[X][Y] = '.';
				}

				// 벽 혹은 문이 아닐 경우 탐색
				if (graph[X][Y] >= 'a' && graph[X][Y] <= 'z') {
					key[graph[X][Y] - 'a'] = true;
					graph[X][Y] = '.';
				}
				if (graph[X][Y] == '$') {
					graph[X][Y] = '.';
					ans++;
				}
				if (graph[X][Y] == '.') {
					check = false;
					que.push({ X, Y });
					visit[X][Y] = true;
				}
			}

		}
		if (check == true) break;
		else {
			while (!tmp.empty()) {
				que.push(tmp.front());
				tmp.pop();
			}
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC; cin >> TC;

	for (int c = 0; c < TC; c++) {
		cin >> N >> M;

		// 입력 받기
		vector<vector<char>> graph(N + 2, vector<char>(M + 2, '.'));
		vector<bool> key(26);

		FOR(i, M) graph[0][i] = '.';
		FOR(i, M) graph[N+1][i] = '.';
		string tmp;
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			for (int j = 1; j <= M; j++) {
				graph[i][j] = tmp[j-1];
			}
		}

		string K; cin >> K;
		if (K != "0") {
			for (int i = 0; i < K.size(); i++) {
				key[K[i] - 'a'] = true;
			}
		}
		cout << bfs(graph, key) << endl;


	}
}