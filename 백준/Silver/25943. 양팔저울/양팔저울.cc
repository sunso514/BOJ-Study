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

struct Location {
	int x, y, time;
};

#define X dx[i] + loc.x
#define Y dy[i] + loc.y

int N, M;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> vec(N);
	FOR(i, N) cin >> vec[i];

	int left = 0;
	int right = 0;
	FOR(i, N) {
		if (left == right) left += vec[i];
		else (right > left) ? left += vec[i] : right += vec[i];
	}
	//cout << "R / L : " << right << " " << left << endl;
	int val = abs(right - left);
	//cout << "VAL : " << val << endl;

	int chu[7] = { 100, 50, 20, 10, 5, 2, 1 };
	int ans = 0;
	FOR(i, 7) {
		ans += val / chu[i];
		val = val % chu[i];
	}
	cout << ans;


}