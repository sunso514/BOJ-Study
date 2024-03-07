#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int ans = -1;
    int best = 0;
    for (int tc = 1; tc <= N; tc++) {
        vector<int> vec(5);
        int tmp = 0;
        FOR(i, 5) cin >> vec[i];
        FOR(i, 5) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    int sumv = (to_string(vec[i] + vec[j] + vec[k])).back() - '0';
                    tmp = max(tmp, sumv);
                }
            }
        }
        if (best <= tmp) {
            ans = tc;
            best = tmp;
        }
    }
    cout << ans;
}