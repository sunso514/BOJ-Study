#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define endl "\n"
using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;

    int now = 0;
    stack<int> tmp;
    stack<int> stk;
    vector<string> ans;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (now < a) while (now < a) {
            now++;
            tmp.push(now);
            ans.push_back("+");
        }

        int t = tmp.top();
        if (t != a){
            cout << "NO";
            return 0;
        }
        stk.push(t);
        ans.push_back("-");
        tmp.pop();
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}