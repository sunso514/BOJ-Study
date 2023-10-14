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

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> vec(2, vector<int>(10));
	FOR(i, 2) FOR(j, 10) cin >> vec[i][j];
	FOR(i, 2) sort(vec[i].begin(), vec[i].end());
	int sum_A = vec[0][9] + vec[0][8] + vec[0][7];
	int sum_B = vec[1][9] + vec[1][8] + vec[1][7];
	cout << sum_A << " " << sum_B;
}