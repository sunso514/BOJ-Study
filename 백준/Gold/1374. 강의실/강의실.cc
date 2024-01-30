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

#define test "test "
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

struct subject {
    int start, end;
};


bool compare(subject& n1, subject& n2) {
    if (n1.start != n2.start) return n1.start < n2.start;
    return n1.end > n2.end;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<subject> time_tb;

    for (int i = 0; i < N; i++) {
        int c, a, b;
        cin >> c >> a >> b;
        time_tb.push_back({a, b});
    }
    sort(time_tb.begin(), time_tb.end(), compare);
    int maxroom = 1;
    int nowroom = 0;
    pq.push(time_tb[0].end);
    for (int i = 1; i < N; i++) {
        pq.push(time_tb[i].end);
        if (pq.top() <= time_tb[i].start) pq.pop();;
    }
    //cout << endl;
    cout << pq.size();

}