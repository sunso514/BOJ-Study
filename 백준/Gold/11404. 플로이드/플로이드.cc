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


vector<vector<int>> g(105, vector<int>(105, 1000000007));
int N, M;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	while (M--) {
		int f, s, cost;
		cin >> f >> s >> cost;
		g[f][s] = min(g[f][s], cost);
	}

	for (int i = 1; i <= N; i++) g[i][i] = 0;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (g[i][j] == 1000000007) cout << "0 ";
			else cout << g[i][j] << " ";
		}
		cout << endl;
	}
}