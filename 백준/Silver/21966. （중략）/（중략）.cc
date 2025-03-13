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
    string st; cin >> st;
    if (N <= 25) {
        cout << st;
        return 0;
    }
    bool double_sent = false;
    for (int i = 12; i < N - 12; i++) {
        if (st[i] == '.') double_sent = true;
    }
    
    if (double_sent == false) {
        cout << st.substr(0, 11) << "..." << st.substr(N - 11, 11);
    } 
    else {
        cout << st.substr(0, 9) << "......" << st.substr(N - 10, 10);
    }
}
