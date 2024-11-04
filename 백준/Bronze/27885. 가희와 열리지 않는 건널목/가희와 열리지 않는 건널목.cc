
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
#include <set>
#include <tuple>

#include <bitset>

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N; 


int main(void) {
    cin.tie(NULL);

    int ANS = 86400;
    int c, h; cin >> c >> h;

    vector<int> tm;
    for (int i = 0; i < c + h; i++) {
        string get; cin >> get; // 00:00:00
        int h, m, s;
        h = stoi(get.substr(0, 2));
        m = stoi(get.substr(3, 5));
        s = stoi(get.substr(6, 8));
        tm.push_back(h * 3600 + m * 60 + s);
    }
    sort(tm.begin(), tm.end());

    int pv = -40;
    int ps;
    for (auto i : tm) {
        if (i - pv >= 40) {
            ps = 40;
        }
        else ps = i - pv;

        ANS -= ps;
        pv = i;
    }
    cout << ANS;
}