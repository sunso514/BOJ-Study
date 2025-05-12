#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define INF 1000000009

int N, r, c;

int main()
{
	cin >> N;
    vector<vector<int>> dp(N+2, vector<int>(N+2));
    vector<vector<int>> mat(N+2, vector<int>(2));
    vector<int> sum(N+2);
    
	for (int i = 1; i <= N; i++)
	{
		cin >> r >> c;
		mat[i][0] = r;
		mat[i][1] = c;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; i + j <= N; j++)
		{
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++)
			{
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + mat[j][0] * mat[k][1] * mat[i+j][1]);
			}
		}

	}
	cout << dp[1][N];
}