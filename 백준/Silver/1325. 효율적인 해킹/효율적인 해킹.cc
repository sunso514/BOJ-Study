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

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        fill(visit.begin(), visit.end(), 0);
        ans.push_back({ i, bfs(i) });
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < N; i++) {
        if (ans[i].second == maxscr) {
            cout << ans[i].first << " ";
        }
    }
}