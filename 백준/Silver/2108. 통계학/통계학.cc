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
vector<int> list(5000001);
//vector<vector<int>> vec;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    int av = 0;
    list.resize(n);


    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        av += a;
        list[i] = a;
    }
    sort(list.begin(), list.end());
    list.resize(n + 1);

    if (round(av / (double)n) == -0) {
        cout << 0 << "\n";
    }
    else cout << round(av / (double)n) << "\n";
    
    cout << list[n / 2] << "\n";



    priority_queue<int> check;
    int bestnum = -1;
    int nowstreak = 0;
    int bisangsikryang;
    if (n == 1) bisangsikryang = list[0];
    else bisangsikryang = list[1];
    
    for (int i = 0; i < n; i++) {
        if (list[i] == list[i + 1]) {
            nowstreak++;
            if (nowstreak > bestnum) {
                bestnum = nowstreak;
                while (!check.empty()) {
                    check.pop();
                }
                check.push(list[i]);
            }
            else if (nowstreak == bestnum) check.push(list[i]);
        }
        else nowstreak = 0;
    }
    if (!check.empty()) {
        if (check.size() == 1) cout << check.top() << "\n";
        else {
            while (check.size() != 2) {
                check.pop();
            }
            cout << check.top() << "\n";
        }
    }
    else cout << bisangsikryang << "\n";

    cout << list[n - 1] - list[0];
}