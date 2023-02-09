#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
//	vector<int> list(time);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<int> stack;

    int time;
    cin >> time;
    int a;
    for (int i = 0; i < time; i++) {
        cin >> a;
        if (a == 0) stack.pop();
        else stack.push(a);
    }
    int res = 0;
    int size = stack.size();
//while (!stack.empty()) 
    for (int i = 0; i < size; i++) {
        res += stack.top();
        stack.pop();
    }
    cout << res;
}