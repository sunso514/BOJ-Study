#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> vec(2, vector<int>(10));
	FOR(i, 2) FOR(j, 10) cin >> vec[i][j];
	FOR(i, 2) sort(vec[i].begin(), vec[i].end());
	cout << vec[0][9] + vec[0][8] + vec[0][7] << " " << vec[1][9] + vec[1][8] + vec[1][7];
}