#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define test "test "
#define endl "\n"

using namespace std;

int N, M;

struct Location {
    int x, depth;
};

vector<int> visit(101);
vector<int> connect(101, 0);
queue<Location> que;

void bfs() {
    Location l;
    while (!que.empty()) {
        l = que.front();
        que.pop();

        for (int i = 1; i <= 6; i++) {
            if (l.x + i == 100) {
                cout << l.depth + 1;
                return;
            }
            if (!visit[l.x + i]) {
                visit[l.x + i] = true;
                if (connect[l.x + i] == 0) que.push({ l.x + i, l.depth + 1 });
                else if (connect[l.x + i] > 0) que.push({ connect[l.x + i], l.depth + 1 });
                else que.push({ connect[l.x + i] * -1 , l.depth + 1 });
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        connect[a] = b;
    }
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        connect[a] = b * -1;
    }
    
    que.push({ 1, 0 });
    bfs();

}