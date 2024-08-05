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

vector<vector<int>> graph;
vector<int> visit;
int cnt = 1;

void dfs(int st) {
	if (visit[st] != 0) return;
	visit[st] = cnt;
	cnt++;

	for (auto n : graph[st]) {
		if (visit[n] != 0) continue;
		else {
			dfs(n);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, R;
	cin >> N >> M >> R;
	graph.resize(N + 1, vector<int>());
	visit.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(R);
	for (int i = 1; i <= N; i++) {
		cout << visit[i] << endl;
	}
}