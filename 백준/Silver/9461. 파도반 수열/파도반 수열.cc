#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <deque>
#include <set>
#include <tuple>
#define test "test "
#define endl "\n"
#define GB " "

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)
int N, P;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T, N;
	cin >> T;
	FOR(i, T) {
		cin >> N;
		vector<long long> dp(101, 1);
		dp[4] = dp[5] = 2;
		for (int j = 6; j <= N; j++) {
			dp[j] = dp[j - 1] + dp[j - 5];
		}
		cout << dp[N] << "\n";
    }
}