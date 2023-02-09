#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
using namespace std;

#define MAX 1000002 // 최대 정점의 개수
#define INF 99999999

//    vector<int> list(time);
//vector<int> list;
//vector<vector<int>> vec;
int n;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    vector<int> dp(1001);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    cout << dp[n];


}