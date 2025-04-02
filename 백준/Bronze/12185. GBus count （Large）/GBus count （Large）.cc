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
#include <iomanip>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;



int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        vector<pair<int, int>> bus(N);
        for (int i = 0; i < N; i++) {
            int A, B;
            cin >> A >> B;
            bus[i] = { A, B };
        }

        int P;
        cin >> P;
        vector<int> city(P);
        for (int i = 0; i < P; i++) cin >> city[i];

        cout << "Case #" << tc << ":";
        for (int i = 0; i < P; i++) {
            int ct = city[i];
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (bus[j].first <= ct && ct <= bus[j].second) {
                    count++;
                }
            }
            cout << " " << count;
        }
        cout << endl;
    }

}
