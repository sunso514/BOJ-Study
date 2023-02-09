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
    queue<int> q;
    int time;
    cin >> time;
    for (int i = 0; i < time; i++) {
        string input;
        cin >> input;
        if (input == "push") {
            int it;
            cin >> it;
            q.push(it);
        }
        if (input == "front") {
            if (q.empty() == 0) cout << q.front() << "\n";
            else cout << -1 << "\n";
        }
        if (input == "back"){
            if (q.empty() == 0) cout << q.back() << "\n";
            else cout << -1 << "\n";
       }
        if (input == "size") cout << q.size() << "\n";
        if (input == "empty") cout << q.empty() << "\n";
        if (input == "pop") {
            if (q.empty() == 0) {
                cout << q.front();
                q.pop();
                cout << "\n";
            }
            else cout << -1 << "\n";
        }
        
    }

}