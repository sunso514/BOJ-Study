
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

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;


vector<vector<int>> vec;

bool check(int a, int b, int c, vector<vector<int>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        int ta = vec[i][2] / 100;
        int tb = vec[i][2] % 100 / 10;
        int tc = vec[i][2] % 10;

        //Strike Count 세기
        int stCount = 0;
        if (ta == a) stCount++;
        if (tb == b) stCount++;
        if (tc == c) stCount++;
        
        if (vec[i][0] != stCount) return false;

        int baCount = 0;
        if (tb == a || tc == a) baCount++;
        if (ta == b || tc == b) baCount++;
        if (ta == c || tb == c) baCount++;

        if (vec[i][1] != baCount) return false;

    }
    return true;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int tc;
    cin >> tc;
    
    vec.resize(tc, vector<int>(3));

    int ans = 0;
    for (int t = 0; t < tc; t++) {
        cin >> vec[t][2] >> vec[t][0] >> vec[t][1];
    }

    for (int i = 1; i <= 9; i++) for (int j = 1; j <= 9; j++) for (int k = 1; k <= 9; k++) {
        if (i == j || j == k || i == k) continue;

        if (check(i, j, k, vec) == true) {
            ans++;
        }
    }
    cout << ans;
}
    