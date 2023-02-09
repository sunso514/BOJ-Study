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
    int time, res;
    cin >> time;
    for (int i = 0; i < time; i++) {
        res = 1;

        int a, b;
        cin >> a >> b;  

        for (int j = 0; j < a; j++) {
            res *= b - j;
            res /= 1 + j;
        }
        cout << res << endl;
    }
    
}