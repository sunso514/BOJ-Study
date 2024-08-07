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
	
	int N;
	cin >> N;
	
	vector<int> bus(N);
	vector<int> diff(N-1);

	for (int i = 0; i < N; i++) {
		cin >> bus[i];
	}
	sort(bus.begin(), bus.end());
	
	for (int i = 0; i < N - 1; i++) {
		diff[i] = bus[i + 1] - bus[i];
	}

	sort(diff.begin(), diff.end());
	int minV = diff[0];
	int count = 0;
	for (int i = 0; i < N - 1; i++) {
		if (minV != diff[count]) break;
		count++;
	}
	cout << minV << " " << count;

}