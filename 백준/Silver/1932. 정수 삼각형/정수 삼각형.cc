
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <bitset>
#define test "Test "

using namespace std;

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;


int N;
vector<vector<int>> list;

int maxn = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    list.resize(N, vector<int>(N, -1));
    int dp[500][500];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> list[i][j];
        }
    }
    dp[0][0] = list[0][0];
    int res = list[0][0];
    for (int depth = 1; depth < N; depth++) {
        for (int cord = 0; cord <= depth; cord++) {

            if (cord == 0) dp[depth][cord] = dp[depth - 1][0] + list[depth][cord];
            else if (cord == depth) dp[depth][cord] = dp[depth - 1][cord-1] + list[depth][cord];
            else dp[depth][cord] = max(dp[depth - 1][cord - 1], dp[depth - 1][cord]) + list[depth][cord];

                
            if (depth + 1 == N) if (res < dp[depth][cord]) res = dp[depth][cord];
        }   
    }

    cout << res;

}