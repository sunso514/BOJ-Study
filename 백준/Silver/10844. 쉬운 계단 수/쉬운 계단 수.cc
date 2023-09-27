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
	
	cin >> N;

	vector<vector<long long>> dp(N, vector<long long>(10, 0));

	FOR(i, 10) dp[0][i] = 1;
	dp[0][0] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
		}
	}


	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[N - 1][i];
	}
	cout << ans % 1000000000;
}