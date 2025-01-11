#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<int> stack;
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int cmd; cin >> cmd;
        
        if (cmd == 1) {
            int a; cin >> a;
            stack.push(a);
        }
        else if (cmd == 2) {
            if (stack.empty() == 0) {
                cout << stack.top() << endl;
                stack.pop();
            }
            else cout << -1 << endl;
        }
        else if (cmd == 3) cout << stack.size() << endl;
        else if (cmd == 4) cout << stack.empty() << endl;
        else{
            cout << ((stack.empty() == 0) ? stack.top() : -1) << endl;
        }
    }
}