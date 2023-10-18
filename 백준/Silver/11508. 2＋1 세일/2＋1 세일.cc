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
	sort(vec.begin(), vec.end());

	long long ans = 0;
	int remove_ct = 0;

	for (int i = 0; i < vec.size() % 3; i++) ans += vec[i];
	//cout << vec.size() % 3 << endl;
	for (int i = N - 1; i > (vec.size() % 3); i--) {
	
		if ((i + 1 - vec.size() % 3) % 3 != 1) ans += vec[i];
	}

	cout << ans;
}