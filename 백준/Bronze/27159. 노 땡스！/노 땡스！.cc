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
    int list[34] = { 0 };
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    int min = 0;
    int res = 0;
    bool streak = false;
    for (int i = 0; i < n; i++) {
        if (streak == false) {
            res += list[i];
            streak = true;
            if (list[i] + 1 != list[i + 1]) {
                streak = false;
            }
        }
        else {
            if (list[i] + 1 != list[i + 1]) {
                streak = false;
            }
        }
    }
    cout << res;
}