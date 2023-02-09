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


//int graph[1][1];
//vector<int> list(5000001);
//vector<vector<int>> vec;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector <int> vec;
    while (true) {
        int time;
        cin >> time;
        if (time == 0) break;
        vec.resize(time * 2);
        int res = 1;
        for (int i = 0; i < 2 * time; i++) {
            cin >> vec[i];
        }

        for (int i = 0; i < time; i++) {
            int a = vec[2 * i];
            int b = vec[2 * i + 1];
            res = res * a - b;
        }
        cout << res << endl;
        

    }


}