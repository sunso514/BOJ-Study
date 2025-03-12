
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
    
    int T, X;
    cin >> T >> X;
    int N; cin >> N;
    FOR(i, N) {
        int a; cin >> a;
        bool check = false;
        for (int i = 0; i < a; i++) {
            int b; cin >> b;
            if (b == X) {
                check = true;
            }
        }
        if (check == false) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
