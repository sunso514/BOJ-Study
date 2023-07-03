#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M;

vector<int> result;
priority_queue<int, vector<int>, greater<int>> que;

vector<int> graph[32002];
vector<int> indegree(32002, 0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) que.push(i);
    }

    while (!que.empty()) {
        int a = que.top();
        que.pop();
        result.push_back(a);

        for (int x : graph[a]) {
            indegree[x]--;
            if (indegree[x] == 0) que.push(x);
        }
    }
    for (int i = 0; i < N; i++) cout << result[i] << " ";
}