#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string A, B; cin >> A >> B;

    int ans = 0;

    if (A.length() == B.length()) {
        for (int i = 0; i < A.length(); i++) {
            if (A[i] != B[i]) break;
            if (A[i] == B[i] && A[i] == '8') ans++;
        }
    }
    cout << ans;
}