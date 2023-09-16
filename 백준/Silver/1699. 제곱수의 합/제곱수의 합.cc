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

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N;
vector<int> dp(1000001, 1);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
    
    dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	int now = 1;

	for (int i = 4; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N];
}