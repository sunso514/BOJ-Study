#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>

using namespace std;
//    vector<int> list(time);
//vector<int> list;



int n, m, streak;

//int graph[1][1];
//vector<int> list(5000001);
//vector<vector<int>> vec;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string a;
 
        getline(cin, a);
        int smallgr = 0, smallgl = 0, biggr = 0, biggl = 0;
        bool no = false;
        for(int now = 0; now < a.length(); now++) {
            //cout << a[now] << endl;
            if (a[now] == '[') biggl++;
            else if (a[now] == ']') {
                if (biggl > biggr) biggr++;
                else {
                    no = true;
                    break;
                }
            }
            else if (a[now] == '(') smallgl++;
            else if (a[now] == ')') {
                if (smallgl > smallgr) smallgr++;
                else {
                    no = true;
                    break;
                }
            }
        }
        if (no == false) {
            if (smallgr == smallgl) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
        else cout << "NO" << "\n";
    }
}