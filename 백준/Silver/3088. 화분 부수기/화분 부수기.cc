#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;
int N;
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