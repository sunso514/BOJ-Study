
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
    queue<int> que;

    while (N--) {
        string cmd; cin >> cmd;
    
        if (cmd == "push") {
            int x; cin >> x;
            que.push(x);
        }
        else if (cmd == "pop") {
            if (que.empty()) cout << -1 << endl;
            else {
                cout << que.front() << endl;
                que.pop();
            }
        }
        else if (cmd == "size") cout << que.size() << endl;
        else if (cmd == "empty") cout << que.empty() << endl;
        else if (cmd == "front") cout << (que.empty() ? -1 : que.front()) << endl;
        else if (cmd == "back") cout << (que.empty() ? -1 : que.back()) << endl;
    }

}
    