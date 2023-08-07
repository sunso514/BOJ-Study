#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    
    cin >> N;

    vector<int> vec;
    vector<int> dp(N);


    FOR(i, N) {
        int a; cin >> a;
        vec.push_back(a);
        dp[i] = a;
    }

    FOR(i, N) {
        FOR(j, i) {
            if (vec[j] >= vec[i]) continue;
            if (dp[i] >= dp[j] + vec[i]) continue;
            dp[i] = dp[j] + vec[i];
        }
    }

    int maxv = 0;
    FOR(i, N) maxv = max(maxv, dp[i]);
    
    cout << maxv;
}