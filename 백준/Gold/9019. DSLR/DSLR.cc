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
#include <ranges>
#include <set>
#define test "test "
#define endl "\n"
using namespace std;

#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int now, goal;
struct JongGang {
    int index;
    string res;
};


vector<int> visit;
vector<JongGang> graph;
queue<JongGang> que;

int rotate(int num, bool left) {
    string getstr = to_string(num);
    string report = "";
    if (getstr.length() < 4) {
        for (int i = getstr.length(); i < 4; i++) {
            report += '0';
        }
    }
    //cout << test;
    //cout << report << " ";
    for (int i = 0; i < getstr.length(); i++) {
        report += getstr[i];
    }
    //cout << report;
    if (left == true) {
        return (report[1] - '0') * 1000 + (report[2] - '0') * 100 + (report[3] - '0') * 10 + (report[0] - '0');
    }
    else return (report[3] - '0') * 1000 + (report[0] - '0') * 100 + (report[1] - '0') * 10 + (report[2] - '0');
}


void bfs() {
    JongGang haja;

    while (!que.empty()) {
        haja = que.front();
        que.pop();

        if (haja.index == goal) {
            cout << haja.res << endl;
            return;
        }

        int tmp;

        tmp = (haja.index * 2) % 10000;
        if (!visit[tmp]) {
            visit[tmp] = true;
            que.push({ tmp, haja.res + "D" });
        }

        tmp = haja.index == 0 ? 9999 : haja.index - 1;
        if (!visit[tmp]) {
            visit[tmp] = true;
            que.push({ tmp, haja.res + "S" });
        }

        tmp = (haja.index % 1000) * 10 + (haja.index / 1000);
        if (!visit[tmp]) {
            visit[tmp] = true;
            que.push({ tmp, haja.res + "L" });
        }

        tmp = haja.index / 10 + (haja.index % 10) * 1000;
        if (!visit[tmp]) {
            visit[tmp] = true;
            que.push({ tmp, haja.res + "R" });
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    visit.resize(10001);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        fill(visit.begin(), visit.end(), 0);
        cin >> now >> goal;
        visit[now] = true;
        que.push({now, "" });
        bfs();
        while (!que.empty()) que.pop();

    }

}