#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

struct Gujochae {
    int loc, time, clip;
};

int S;
vector<vector<int>> visit;
queue<Gujochae> que;

void bfs() {
    Gujochae now;
    while (!que.empty()) {
        now = que.front();
        que.pop();

        if (now.loc == S) {
            cout << now.time;
            return;
        }

        if (visit[now.loc][now.loc] == 0) {
            visit[now.loc][now.loc] = 1;
            que.push({ now.loc, now.time + 1, now.loc });
        }

        if (now.loc + now.clip < 1010) {
            if (visit[now.loc + now.clip][now.clip] == 0) {
                visit[now.loc + now.clip][now.clip] = 1;
                que.push({ now.loc + now.clip, now.time + 1, now.clip });
            }
        }
        
        if (now.loc - 1 > 1) {
            if (visit[now.loc - 1][now.clip] == 0) {
                visit[now.loc - 1][now.clip] = 1;
                que.push({ now.loc - 1, now.time + 1, now.clip });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> S;
    
    visit.resize(1010, vector<int>(1010, 0));
    que.push({ 1, 0, 0});
    bfs();

}