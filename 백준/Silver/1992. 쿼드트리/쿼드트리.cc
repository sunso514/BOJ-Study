#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N;

vector<vector<int>> vec;
vector<char> ans;

bool check_comp(int x, int y, int s) {
	int first = vec[x][y];
	for (int i = x; i < x+s; i++) {
		for (int j = y; j < y + s; j++) {
			if (first != vec[i][j]) return false;
		}
	}
	return true;
}

void QTree(int x, int y, int s) {
	if (check_comp(x, y, s) == true) {
		ans.push_back(vec[x][y] + '0');
		return;
	}

	ans.push_back('(');
	QTree(x, y, s / 2);
	QTree(x, y + (s / 2), s / 2);
	QTree(x + (s / 2), y, s / 2);
	QTree(x + (s / 2), y + (s / 2), s / 2);
	ans.push_back(')');
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	vec.resize(N, vector<int>(N));

	FOR(i, N) {
		string nme; cin >> nme;
		FOR(j, N) vec[i][j] = nme[j] - '0';
	}

	QTree(0, 0, N);
	for (char i : ans) cout << i;
} 