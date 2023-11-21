#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<int> stack;
    int time;
    cin >> time;
    for (int i = 0; i < time; i++) {
        string input;
        cin >> input;
        if (input == "push") {
            int it;
            cin >> it;
            stack.push(it);
        }
        if (input == "top") {
            if (stack.empty() == 0) cout << stack.top() << "\n";
            else cout << -1 << "\n";
        }
        if (input == "size") cout << stack.size() << "\n";
        if (input == "empty") cout << stack.empty() << "\n";
        if (input == "pop") {
            if (stack.empty() == 0) {
                cout << stack.top();
                stack.pop();
                cout << "\n";
            }
            else cout << -1 << "\n";
        }
        
    }

}