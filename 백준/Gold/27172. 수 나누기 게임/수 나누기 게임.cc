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

#define MAX 1000002 // 최대 정점의 개수
#define INF 99999999

//    vector<int> list(time);
//vector<int> list;
//vector<vector<int>> vec;

int times;
vector<int> check(MAX);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    map<int, int> m;
    cin >> times;
    vector<int> list;
    for (int i = 0; i < times; i++) {
        int a;
        cin >> a;
        list.push_back(a);
        check[a] = true;
        m.insert({ a, 0 });
    }

    for (int i = 0; i < times; i++) {
        int now = list[i];
        int firstnow = list[i];
        int count = 2;
        
        while (now < MAX) {
            if (now * count > 1000001) break;
            if (check[now * count] == true) {
                m[now * count]--;
                m[firstnow]++;
            }
            count++;
        }
    }

    for (int i = 0; i < times; i++) {
        cout << m[list[i]];
        if (i + 1 != times) {
            cout << " ";
        }
    }



}