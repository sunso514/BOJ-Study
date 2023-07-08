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


vector<int> graph[501];
vector<int> indegree(501);
vector<int> result(501);
vector<int> b_time(501);

queue<int> que;


int N;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> b_time[i];

		while (true) {
			int a; cin >> a;
			if (a == -1) break;
			graph[a-1].push_back(i);
			indegree[i]++;
		}
	}

	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0) {
			result[i] = b_time[i];
			que.push(i);
		}
	}

	while (!que.empty()) {
		int tmp = que.front();
		que.pop();

		for (int nxt : graph[tmp]) {
			indegree[nxt]--;

			result[nxt] = max(result[nxt], result[tmp] + b_time[nxt]);
			if (indegree[nxt] == 0) que.push(nxt);
		}
	}
	FOR(i, N) cout << result[i] << endl;
}