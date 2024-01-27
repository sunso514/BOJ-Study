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

#include <bitset>

#define test "test "
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

#define X loc.x + dx[i]



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S, T;
    cin >> S >> T;

    while (S.size() < T.size()) {
        if (T[T.size() - 1] == 'A'){
            T.pop_back();
        }
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    if (T == S) cout << 1;
    else cout << 0;
}