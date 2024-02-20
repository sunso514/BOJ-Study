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

bool oper(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;
    int a = 0, b = 0;
    
    vector<bool> check(S.length());
    FOR(i, S.length()) {
        if (S[i] == '0') a++;
        else b++;
    }
    a /= 2; b /= 2;
    for (int i = S.length() - 1; i >= 0; i--) {
        if (S[i] == '0' && a > 0) {
            check[i] = true;
            a--;
        }
    }
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '1' && b > 0) {
            b--;
            check[i] = true;
        }
    }

    FOR(i, S.length()) {
        if (check[i] == false) cout << S[i];
    }


}


