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

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;

int N, M;
vector<bool> check;
vector<int> list;

struct Location {
    int cord, depth;
    queue<int> moves;
};

void dfs(Location loc) {
    if (loc.depth == M) { // 수열 최대 길이에 도달
        while (!loc.moves.empty()) {
            cout << loc.moves.front() << " ";
            loc.moves.pop();
        }
        cout << "\n";
        return;
    }
    for (int i = loc.cord; i <= N; i++) {
        if (!check[i]) {
            queue<int> moves = loc.moves;
            moves.push(list[i-1]);

            check[i] = true; // 방문 처리
            dfs({ i, loc.depth + 1, moves });
            check[i] = false;
        }
    }
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    check.resize(N + 1);
    list.resize(N+1);
    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }
    list.resize(N );
    sort(list.begin(), list.end());
    dfs({ 1, 0 });
}