
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
#include <iomanip>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)
#define INF 1000000009

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int N, r, c;
	
	cin >> N;
	vector<vector<int>> dp(N + 1, vector<int>(N + 1));
	vector<vector<int>> mat(N + 1, vector<int>(2));

	for (int i = 1; i <= N; i++) {
		cin >> r >> c;
		mat[i][0] = r;
		mat[i][1] = c;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; i + j <= N; j++)
		{
			dp[j][i + j] = INF;
			for (int k = j; k < i + j; k++)
			{
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + mat[j][0] * mat[k][1] * mat[i + j][1]);
			}
		}

	}

	cout << dp[1][N];
}
