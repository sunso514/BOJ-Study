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

	vector<long long> dp(1000001);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 4; i <= N; i++) {
		dp[i] = (dp[i] + (dp[i - 1] + dp[i - 2])) % 1000000007;
	}
	cout << dp[N];

}