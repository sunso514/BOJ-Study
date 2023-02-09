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


//int graph[1][1];
//vector<int> list(5000001);
//vector<vector<int>> vec;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {

        string get;
        cin >> get;

        cout << get[0] << get[get.length() - 1];
        cout << endl;
    }
}