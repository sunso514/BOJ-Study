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
#define test "test "
#define endl "\n"
using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, M;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    priority_queue<int> p_que;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (a == 0) {
            if (p_que.empty()) cout << 0 << endl;
            else {
                cout << p_que.top() << endl;
                p_que.pop();
            }
        }
        else p_que.push(a);
    }
}