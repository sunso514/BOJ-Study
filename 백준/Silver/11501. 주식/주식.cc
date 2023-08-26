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
#define GB " "

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

struct Loc{
    int start, end, cost;
};

int T;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;


    FOR(tc, T) {
        int N; cin >> N;

        vector<int> dy(N);

        FOR(i, N) cin >> dy[i];

        long long ans = 0;
        int max_num = dy[N-1];
        for(int i = N-2; i >= 0; i--){
            if (max_num > dy[i]) {
                ans += (max_num - dy[i]);
            }
            else {
                max_num = dy[i];
            }
        }
        cout << ans << endl;
    }


}