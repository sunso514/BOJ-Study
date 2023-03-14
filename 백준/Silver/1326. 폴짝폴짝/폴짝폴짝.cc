
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

struct Location {
    int x, depth;
};

queue<Location> que;
vector<int> graph;
vector<int> visit;

int N, goal;

void bfs() {
    Location l;
    while (!que.empty()) {
        l = que.front();
        que.pop();
        //cout << "debug : " << l.x << " " << l.depth << endl;
        if (l.x == goal - 1) {
            cout << l.depth;
            return;
        }

        int bs = graph[l.x];
        int count = 1;
        
        while (true) {
            if (l.x - bs * count < 0) break;
            //cout << test << " " << l.x;
            if (!visit[l.x - bs * count]) {
                que.push({ l.x - bs * count, l.depth + 1 });
                visit[l.x - bs * count] = true;
            }
            count++;
        }
        count = 1;

        while (true) {
            if (l.x + bs * count >= N) break;
            if (!visit[l.x + bs * count]) {
                //cout << " 아 짜증나" << l.x + bs * count << " " << l.depth + 1;
                que.push({ l.x + bs * count, l.depth + 1 });
                visit[l.x + bs * count] = true;
            }
            count++;
        }
    }
    cout << -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        graph.push_back(a);
    }

    visit.resize(N, 0);

    int first; cin >> first;  
    que.push({ first-1, 0 });
    cin >> goal;
    bfs();
}