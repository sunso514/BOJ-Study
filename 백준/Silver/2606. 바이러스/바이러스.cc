#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>

using namespace std;
//	vector<int> list(time);
//vector<int> list;

int n, m;
int c;

vector<bool> check;
vector<vector<int>> nt;

void dfs(int com) {
	check[com] = 1;
	for (int i : nt[com]) { // nt[com] 에서 다 가져옴
		if (!check[i]) {
			dfs(i);
			c++;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	nt.resize(n + 1);
	check.resize(n + 1);
	int con, nect;
	c = 0;
	for (int i = 0; i < m; i++) {
		cin >> con >> nect;
		nt[con].push_back(nect);
		nt[nect].push_back(con);
	}
	dfs(1);
	cout << c;

}