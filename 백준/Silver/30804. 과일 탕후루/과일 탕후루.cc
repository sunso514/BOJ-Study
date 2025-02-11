
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


struct sign {
    int D, R, G; // D : location, R, G : red/green light duration 
};

bool compare(sign& a, sign& b) {
    if (a.D <= b.D) return true;
    return false;
}


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;

    // 탕후루 목록
    vector<int> vec(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    int maxV, l, r;
    l = r = maxV = 0;
    
    // 탕후루 현재 몇개가 꽂혔나
    vector<int> howmany(10, 0);

    int type = 0;
    int now = 0;
    while (r < N) {
        if (howmany[vec[r]] == 0) {
            type++;
        }
        howmany[vec[r]]++;
        now++;
        if (type <= 2) maxV = max(maxV, now);

        while (type >= 3 && l < r) {
            howmany[vec[l]]--;
            now--;
            if (howmany[vec[l]] == 0) type--;
            l++;
        }
        r++;
    }
    std::cout << maxV;
}
    