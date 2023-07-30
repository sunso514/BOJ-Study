#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long dp[36];

	dp[0] = 1;

	for (int now = 1; now <= 35; now++) {
		long long tmp = 0;
		for (int i = 0; i < now; i++) {
			tmp += dp[i] * dp[now-1-i];
		}
		dp[now] = tmp;
	}
	cin >> N;
	cout << dp[N];
} 