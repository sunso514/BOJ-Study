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
#define test "test "
#define endl "\n"

using namespace std;

struct Icecream {
    int x, depth;
};


vector<int> visit(1000001, 0);
vector<int> path(1000001, -1);
queue<Icecream> que;
deque<int> pathtmp;
int N, M;
int low = 0, high = 0;

void bfs() {
    Icecream loc;
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        if (loc.x == M) { // 동생 찾았다
            cout << loc.depth << endl; // 시간 출력
             
            int trace = M; // 경로 역추적
            while (trace != -1) {   
                pathtmp.push_front(trace);
                trace = path[trace];
            }
            return;
        }
        if (!visit[loc.x + 1] && loc.x + 1 <= 100000) {
            que.push({ loc.x + 1 , loc.depth + 1 });
            path[loc.x + 1] = loc.x;
            visit[loc.x + 1] = true;
        }
        if (!visit[loc.x - 1] && loc.x - 1 >= 0) {
            que.push({ loc.x -1 , loc.depth + 1 });
            path[loc.x - 1] = loc.x;
            visit[loc.x - 1] = true;
        }
        if (!visit[loc.x * 2] && loc.x * 2 <= 100000) {
            que.push({ loc.x * 2 , loc.depth + 1 });
            path[loc.x * 2] = loc.x;
            visit[loc.x * 2] = true;
        }
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    que.push({ N, 0 });
    visit[N] = true;
    bfs();

    for (int i = 0; i < pathtmp.size(); i++) {
        cout << pathtmp[i] << " ";
    }

}