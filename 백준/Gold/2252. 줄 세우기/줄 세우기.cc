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
vector<int> graph[32002];
vector<int> indegree(32002);

vector<int> result;
queue<int> que;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) que.push(i);
    }
    
    while (!que.empty()) {
        int a = que.front();
        que.pop();
        result.push_back(a);

        for (int x : graph[a]) {
            indegree[x]--;
            if (indegree[x] == 0) que.push(x);
        }
    }

    for (auto res : result) cout << res << " ";
}