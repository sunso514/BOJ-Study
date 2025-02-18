
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


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;

    FOR (tc, N) {
        int S; cin >> S;
        vector<int> red;
        vector<int> blue;

        FOR(i, S) {
            string get; cin >> get;
            if (get[get.size() - 1] == 'R') {
                get.pop_back();
                red.push_back(stoi(get));
            }
            else {
                get.pop_back();
                blue.push_back(stoi(get));
            }
        }

        sort(red.rbegin(), red.rend());
        sort(blue.rbegin(), blue.rend());
        int ans = 0;
        FOR(i, min(red.size(), blue.size())) {
            ans += red[i] + blue[i] - 2;
        }
        cout << "Case #" << tc + 1 << ": " << ans << "\n";
    }

}
    