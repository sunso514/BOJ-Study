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
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, M;


vector<int> result;
queue<int> que;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int cases; cin >> cases;

    for (int t_case = 0; t_case < cases; t_case++) {
        vector<int> cost(1002, 0);
        vector<int> dp(1002, 0);
        vector<int> graph[1002];
        vector<int> indegree(1002, 0);

        cin >> N >> M;

        for (int i = 1; i <= N; i++) cin >> cost[i];

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }

        int goal; cin >> goal;

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) que.push(i);
            dp[i] = cost[i];
        }

        while (!que.empty()) {
            int a = que.front();
            que.pop();
            result.push_back(a);

            for (int x : graph[a]) {
                indegree[x]--;
                dp[x] = max(dp[x], dp[a] + cost[x]);

                if (indegree[x] == 0) que.push(x);
            }
        }
        cout << dp[goal] << endl;
    }

}