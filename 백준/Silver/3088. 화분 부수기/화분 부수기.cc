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


#define X dx[i] + loc.x
#define Y dy[i] + loc.y

int N, M;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<vector<int>> vec(N, vector<int>(3));
	vector<bool> visit(1000001);
	FOR(i, N) {
		cin >> vec[i][0];
		cin >> vec[i][1];
		cin >> vec[i][2];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		bool check = true;
		FOR(j, 3) {
			if (visit[vec[i][j]] == true) {
				check = false;
			}
			else visit[vec[i][j]] = true;
		}
		if (check == true) ans++;
	}
	cout << ans;
}