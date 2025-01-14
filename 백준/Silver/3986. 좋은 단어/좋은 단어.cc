
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

    int N; cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++) {
        string get; cin >> get;
        
        stack<int> stk; // A : 0 , B : 1

        for (auto c : get) {
            int code = c - 'A';
            if (stk.empty()) {
                stk.push(code);
                continue;
            }

            if (stk.top() == code) stk.pop();
            else stk.push(code);
        }
        if (stk.empty() == true) {
            count++;
        }
    }
    cout << count;
}
    