
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

    string N; cin >> N;

    stack<int> stk;

    int fail = 0;
    for (auto c : N) {
        int code = c - '(';
        if (stk.empty()) {
            if (code == 1) fail++;
            else stk.push(code);
            continue;
        }
        if (stk.top() == 0 && code == 1) stk.pop();
        else stk.push(code);
    }
    cout << fail + stk.size();

}
    