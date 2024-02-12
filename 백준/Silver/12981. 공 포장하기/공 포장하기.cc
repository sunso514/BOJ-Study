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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, G, B;
    cin >> R >> G >> B;
    int ans = min(min(R, G), B);
    R -= ans;
    G -= ans;
    B -= ans;
    ans += R / 3 + G / 3 + B / 3;
    R %= 3;
    G %= 3;
    B %= 3;
    
    if (R == 2) {
        R = 0;
        ans++;
    }
    if (G == 2) {
        G = 0;
        ans++;
    }
    if (B == 2) {
        B = 0;
        ans++;
    }

    if (R+G+B> 0){
        ans++;
    }
    cout << ans;

}


