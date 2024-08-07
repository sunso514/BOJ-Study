#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	vector<int> box(N); 
	vector<int> dp(N, 1);
	FOR(i, N) cin >> box[i];
	int ans = 1;
	for (int i = 1; i < N; i++) {

		for (int check = 0; check < i; check++) {
			if (box[i] > box[check]) {
				dp[i] = max(dp[i], dp[check] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}