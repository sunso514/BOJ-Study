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



int F, S, G, U, D;
queue<pair<int, int>> que;
vector<int> building;

int bfs() {
	pair<int, int> loc;

	while (!que.empty()) {
		loc = que.front();
		que.pop();
		if (loc.first == G) return loc.second;

		if (loc.first + U <= F) {
			if (building[loc.first + U] == 0) {
				que.push({ loc.first + U, loc.second + 1 });
				building[loc.first + U] = true;
			}
		}
		if (loc.first - D >= 1) {
			if (building[loc.first - D] == 0) {
				que.push({ loc.first - D, loc.second + 1 });
				building[loc.first - D] = true;
			}
		}
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> F >> S >> G >> U >> D;

	if (G == S) {
		cout << 0;
		return 0;
	}

	if (D == 0 && S > G) {
		cout << "use the stairs";
		return 0;
	}
	if (U == 0 && S < G) {
		cout << "use the stairs";
		return 0;
	}

	building.resize(F + 1, 0);

	que.push({ S, 0 });
	int res = bfs();
	if (res == 0) cout << "use the stairs";
	else cout << res;
	
}