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
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

vector<int> vol;
vector<vector<bool>> dp;

int N, S, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S >> M;
    dp.resize(N, vector<bool>(M + 1));

    FOR(i, N) {
        int a; cin >> a;
        vol.push_back(a);
    }

    // 초기 세팅
    if (S + vol[0] <= M) dp[0][S + vol[0]] = true;
    if (S - vol[0] >= 0) dp[0][S - vol[0]] = true;

    FOR(index, N-1) {
        FOR(volume, M+1){
            //cout << index << " " << volume << endl;
            if (dp[index][volume] == true) {
                if (volume + vol[index+1] <= M) dp[index + 1][volume + vol[index+1]] = true;
                if (volume - vol[index+1] >= 0) dp[index + 1][volume - vol[index+1]] = true;
            }
        }
    }
    for (int i = M; i >= 0; i--) {
        if (dp[N - 1][i] == true) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}