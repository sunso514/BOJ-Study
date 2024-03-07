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



vector<vector<int>> graph;
vector<int> visit(10001);
vector<pair<int, int>> ans;
queue<int> que;

// 풀이 로직
/**
 dynamic programming 처럼 해보기..?
 **/
int maxscr = 0;

int bfs(int n) {

    visit.assign(10001, false);
    que.push(n);
    visit[n] = true;
    int hax = 0;
    while (!que.empty()) {
        int loc = que.front();
        que.pop();
        for (auto i : graph[loc]) {
            if (visit[i] == false) {
                visit[i] = true;
                que.push(i);
                hax++;
            }
        }
    }
    maxscr = max(hax, maxscr);
    return hax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int ans = -1;
    int best = 0;
    for (int tc = 1; tc <= N; tc++) {
        vector<int> vec(5);
        int tmp = 0;
        FOR(i, 5) cin >> vec[i];
        FOR(i, 5) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    int sumv = (to_string(vec[i] + vec[j] + vec[k])).back() - '0';
                    tmp = max(tmp, sumv);
                }
            }
        }
        if (best <= tmp) {
            ans = tc;
            best = tmp;
        }
    }
    cout << ans;
}