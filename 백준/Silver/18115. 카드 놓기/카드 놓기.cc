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

#define test "test "
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

deque<int> deq;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> cmds(N);
    for (int i = 0; i < N; i++) {
        cin >> cmds[i];
    }

    int now = 1;
    for (int i = N - 1; i >= 0; i--) {
        if (cmds[i] == 1) deq.push_back(now);
        else if (cmds[i] == 2) {
            int tmp = deq.back();
            deq.pop_back();
            deq.push_back(now);
            deq.push_back(tmp);
        }
        else deq.push_front(now);
        now += 1;
    }
    for (int i = N - 1; i >= 0; i--) {
        cout << deq[i] << " ";
    }
}