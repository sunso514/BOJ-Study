#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define test "test "
using namespace std;

struct Location {
    int x, y;
};

int N, M;
vector<Location> store;
vector<Location> home;
vector<vector<int>> dis; // home 와 store와의 좌표 계산
vector<int> vcheck;

struct dfsLoc {
    int cord, depth;
    queue<int> log;
};

int minres = 1000000007;
void dfs(dfsLoc loc) {
    if (loc.depth == M) {
        int res = 0;
        vector<int> dismin(home.size(), 1000005);
        while (!loc.log.empty()) {
            for (int i = 0; i < home.size(); i++) 
                if (dis[loc.log.front()][i] <= dismin[i]) {
                    dismin[i] = dis[loc.log.front()][i];
                }
            loc.log.pop();
        }
        for (int i = 0; i < home.size(); i++) res += dismin[i];
        if (res < minres) minres = res;
    }

    for (int i = loc.cord; i < store.size(); i++) {
        if (!vcheck[i]) {
            queue<int> log = loc.log;
            log.push(i);
            vcheck[i] = true;
            dfs({ i, loc.depth + 1 , log });
            vcheck[i] = false;
        }
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) {
            int a; cin >> a;
            if (a == 1) home.push_back({ i, j }); //home의 좌표 보관
            if (a == 2) store.push_back({ i, j }); // vector의 좌표 보관
        }

    dis.resize(store.size(), vector<int>(home.size(), 0));
    
    // 모든 home, 모든 store 거리 계산
    int count = 0;
    for (Location locStore : store) {
        int countst = 0;
        for (Location locHome : home) {
            int inp = abs(locStore.x - locHome.x) + abs(locStore.y - locHome.y);
            dis[count][countst] = inp;
            countst++;
        }
        count++;
    }
    vcheck.resize(store.size() + 1);
    dfs({ 0, 0 });
    cout << minres;
}