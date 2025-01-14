
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

int N; 

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    string get; cin >> get;
    long long lst[4] = { 0, };

    for (auto i : get) {
        if (i == 'A') lst[0]++;
        if (i == 'C') lst[1]++;
        if (i == 'G') lst[2]++;
        if (i == 'T') lst[3]++;
    }

    long long ans = 1;
    for(int i = 0; i < 4; i++){
        if (lst[i] == 0) {
            cout << 0;
            return 0;
        }
        ans *= lst[i];
        ans %= 1000000007;
    }
    cout << ans; // 12866번 문제 답안

}
    