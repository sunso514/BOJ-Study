#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<int> dp(N, 0);
	vector<int> lst(N, 0);
	
	FOR(i, N) cin >> lst[i];

	dp[0] = lst[0];
	dp[1] = lst[0] + lst[1];
	dp[2] = max(lst[0] + lst[2], lst[1] + lst[2]);

	for (int i = 3; i < N; i++) {
		dp[i] = max(lst[i] + lst[i - 1] + dp[i - 3], lst[i] + dp[i - 2]);
	}
	cout << dp[N-1];
} 