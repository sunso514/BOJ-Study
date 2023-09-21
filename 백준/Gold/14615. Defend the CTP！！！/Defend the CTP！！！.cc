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


#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

vector<vector<char>> world;

int N, M;


vector<vector<int>> graph_a;
vector<vector<int>> graph_b;
vector<vector<int>> visit;

void bfs(bool reverse) {
	queue<int> que;
	if (!reverse) que.push(1);
	else que.push(N);

	while (!que.empty()) {
		int loc = que.front();
		que.pop();

		visit[reverse][loc] = true;
		
		for (auto x : ((reverse == false) ? (graph_a[loc]) : (graph_b[loc]))) {
			if (visit[reverse][x] == true) continue;
			visit[reverse][x] = true;
			que.push(x);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	graph_a.resize(N + 1, vector<int>());
	graph_b.resize(N + 1, vector<int>());
	visit.resize(2, vector<int>(N + 1));
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph_a[a].push_back(b);
		graph_b[b].push_back(a);
	}

	bfs(false);
	bfs(true);
	//cout << "test" << endl;
	for (int i = 1; i <= N; i++) {
		//cout << visit[0][i] << " ";
		//cout << visit[1][i] << endl;
	}


	int T; cin >> T;
	FOR(tcase, T) {
		int a; cin >> a;
		if (visit[0][a] == true && visit[1][a] == true) {
			cout << "Defend the CTP";
		}
		else cout << "Destroyed the CTP";
		cout << endl;
	}
}