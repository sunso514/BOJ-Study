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


int N, M;
vector<vector<int>> graph;
vector<vector<int>> visit;

void dfs(int x, int y, int block) {
	visit[x][y] = true;
	if (block == 0) {
		if (x + 1 >= N) return;
		if (graph[x + 1][y] == block) dfs(x + 1, y, block);
	}
	else {
		if (y + 1 >= M) return;
		if (graph[x][y + 1] == block) dfs(x, y + 1, block);
	}
	
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	
	graph.resize(N, vector<int>(M));
	visit.resize(N, vector<int>(M));

	FOR(i, N) {
		string gp;
		cin >> gp;
		FOR(j, M) graph[i][j] = (gp[j] == '-') ? 1 : 0;
	}

	int count = 0;
	FOR(i, N) FOR(j, M){
		if (visit[i][j] == true) continue;
		dfs(i, j, graph[i][j]);
		count++;
	}
	cout << count;


} 