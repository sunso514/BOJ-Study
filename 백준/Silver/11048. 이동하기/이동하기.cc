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

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N, vector<int>(M));
	vector<vector<int>> dp(N, vector<int>(M));
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	dp[0][0] = graph[0][0];
	int dx[3] = { 1, 0, 1 };
	int dy[3] = { 0, 1, 1 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			for (int k = 0; k < 3; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= N || x < 0) continue;
				if (y >= M || y < 0) continue;
				dp[x][y] = max(dp[x][y], dp[i][j] + graph[x][y]);
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << dp[N - 1][M - 1];
}