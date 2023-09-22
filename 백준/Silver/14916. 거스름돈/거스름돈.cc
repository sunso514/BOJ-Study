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

vector<vector<char>> world;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> dp(100001, 1000000);
	
	dp[2] = 1;
	dp[5] = 1;

	for (int i = 2; i < N; i++) {
		if (dp[i] != 1000000) {
			if (i + 2 <= 100000){
				dp[i + 2] = min(dp[i + 2], dp[i] + 1);
			}
			if (i + 5 <= 100000) {
				dp[i + 5] = min(dp[i + 5], dp[i] + 1);
			}
		}
	}
	if (dp[N] == 1000000) cout << -1;
	else cout << dp[N];
}