#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<int> stk;
    int a, N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a == 0) stk.pop();
        else stk.push(a);
    }
    int res = 0;
    int size = stk.size();
    for (int i = 0; i < size; i++) {
        res += stk.top();
        stk.pop();
    }
    cout << res;
}