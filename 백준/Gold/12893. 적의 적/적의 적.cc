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

vector<int> parent;
vector<int> enemy;
int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	int xp = find(x);
	int yp = find(y);
	if (xp == yp) return;
	parent[xp] = yp;
	return;
	if (parent[xp] > parent[yp]) parent[xp] = yp;
	else parent[yp] = xp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	parent.resize(N + 1, -1);
	enemy.resize(N + 1, 0);
	FOR(i, M) {
		int a, b;
		cin >> a >> b;

		if (find(a) == find(b)) {
			cout << 0;
			return 0;
		}

		if (enemy[a] == 0) enemy[a] = b;
		else Union(enemy[a], b);

		if (enemy[b] == 0) enemy[b] = a;
		else Union(enemy[b], a);
	}
	cout << 1;
}