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
	
	int N; cin >> N;
	vector<int> card(N);
	int maxV = -1;
	int tmpidx = -1;
	FOR(i, N) {
		cin >> card[i];
		if (maxV < card[i]) {
			tmpidx = i;
			maxV = card[i];
		}
	}

	int gold = 0;
	for (int i = 0; i < N; i++) {
		if (i == tmpidx) continue;
		gold += card[i] + maxV;
	}
	cout << gold;


}