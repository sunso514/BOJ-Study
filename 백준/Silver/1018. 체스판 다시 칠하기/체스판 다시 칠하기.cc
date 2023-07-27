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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	vector<vector<int>> vec(N, vector<int>(M));

	// input
	FOR(i, N) {
		string get; cin >> get;
		FOR(j, M) vec[i][j] = (get[j] == 'W' ? 0 : 1);
	}

	int res = 10000000;

	FOR(bti, N - 7) FOR(btj, M - 7) {
		int check = 0;
		//cout << endl;
		FOR(tmc, 2) {
			int cnt = 0;
			FOR(i, 8) {
				check = (tmc + i) % 2;
				FOR(j, 8) {
					//cout << ((check == 0) ? 'W' : 'B');
					if (vec[i+bti][j+btj] != check) cnt++;
					check = (check + 1) % 2;
				}
				//cout << endl;
			}
			//cout << cnt;
			//cout << endl;
			res = min(res, cnt);
		}
	}

	cout << res;
} 