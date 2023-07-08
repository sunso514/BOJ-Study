#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

struct mst {
	int cost, a, b;
};

bool compare(mst a, mst b) {
	return a.cost > b.cost;
}

vector<int> par(10001, -1);
vector<mst> edge;

int Find(int cd) {
	if (par[cd] < 0) return cd;
	return par[cd] = Find(par[cd]);
}

bool Union(int x, int y) {
	int xp = Find(x);
	int yp = Find(y);

	if (xp == yp) return 0;
	if (par[xp] > par[yp]) par[xp] = yp;
	else par[yp] = xp;
	return 1;
}

int N, K;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	int cnt_e = 0;
	int res = 0;

	for (int i = 0; i < K; i++) {
		int a, b, cost, couple;
		cin >> a >> b >> cost >> couple;
		if (couple == 0) {
			edge.push_back({ cost, a, b });
			res += cost;
		}
		else {
			Union(a, b);
		}
	}

	sort(edge.begin(), edge.end(), compare);
	for (int i = 0; i < edge.size(); i++) {
		mst tmp = edge[i];
		if (Union(tmp.a, tmp.b) == false) continue;

		cnt_e++;
		res -= tmp.cost;
	}
	cout << res;
}