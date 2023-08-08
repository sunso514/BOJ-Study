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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q;

    cin >> N >> M >> Q;

    vector<vector<int>> vec(N, vector<int>(M));
    vector<int> plus_a(N);
    vector<int> plus_b(M);


    FOR(i, Q) {
        int cmd, r, val;
        cin >> cmd >> r >> val;

        if (cmd == 2) {
            plus_b[r-1] += val;
        }
        else plus_a[r-1] += val;
    }



    FOR(i, N) {
        FOR(j, M) cout << plus_a[i] + plus_b[j] << " ";
        cout << endl;
    }
}