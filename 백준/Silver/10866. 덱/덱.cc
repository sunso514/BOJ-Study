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
    deque<int> d;
    int abc;
    for (int i = 0; i < n; i++) {
        string get;
        cin >> get;

        if (get == "push_back") {
            cin >> abc;
            d.push_back(abc);
        }
        if (get == "push_front") {
            cin >> abc;
            d.push_front(abc);
        }
        if (get == "pop_front") {
            if (!d.empty()) {
                cout << d.front() << "\n";
                d.pop_front();
            }
            else cout << -1 << "\n";
        }
        if (get == "pop_back") {
            if (!d.empty()) {
                cout << d.back() << "\n";
                d.pop_back();
            }
            else cout << -1 << "\n";
        }
        
        if (get == "size") {
            cout << d.size() << "\n";
        }
        if (get == "empty") {
            if (!d.empty()) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
        if (get == "front") {
            if (!d.empty()) {
                cout << d.front() << "\n";
            }
            else cout << -1 << "\n";
        }
        if (get == "back") {
            if (!d.empty()) {
                cout << d.back() << "\n";
            }
            else cout << -1 << "\n";
        }

    }
}