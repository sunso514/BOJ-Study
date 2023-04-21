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

#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

struct Location {
    int x, y, depth;
};
vector<vector<int>> graph;
vector<vector<int>> visit;
queue<Location> que;
vector<Location> gns;

bool check[10];
vector<Location> Virus_Locations;
vector<Location> Unav_Virus;

int mins = 1000000007;
int N, M, max, safe;

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


bool checkVoid(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) return false;
    return true;
}

int bfs() {
    Location loc;
    int count = 0;
    fill(visit.begin(), visit.end(), vector<int>(N, 0));
    while (!que.empty()) {
        loc = que.front();
        que.pop();
        visit[loc.x][loc.y] = true;
        FOR(i, 4) {
            if (!checkVoid(X, Y)) continue;
            if (graph[X][Y] != 1 && visit[X][Y] != -1 && !visit[X][Y]) {
                que.push({ X, Y, loc.depth+1 });
                visit[X][Y] = true;
                if (graph[X][Y] == 0) count++;
                if (safe - count == 0) { 
                    return loc.depth + 1;
                }
                
            }
        }
        
    }
    return 1000000007;
}

void dfs(int cord, int depth) {
    if (depth == M) {
        while (!que.empty()) que.pop();
        FOR(i, M) que.push(Virus_Locations[i]);
        int tmp = bfs();
        if (tmp < mins) mins = tmp;
        return;
    }
    //cout << " 현재 cord: " << cord << endl;
    for (int i = cord; i < gns.size(); i++) {
        if (check[i]) continue;
        //cout << " 현재 i: " << i << " ";
        check[i] = true;
        Virus_Locations.push_back(gns[i]);
        dfs( i, depth+1 );
        Virus_Locations.pop_back();
        check[i] = false;
    }
    
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    graph.resize(N, vector<int>(N));
    visit.resize(N, vector<int>(N));
    safe = N * N;
    FOR(i, N) FOR(j, N) {
        cin >> graph[i][j];
        if (graph[i][j] == 1) safe--;
        if (graph[i][j] == 2) {
            safe--;
            Unav_Virus.push_back({ i, j, 0 });
            gns.push_back({ i, j, 0 });
        }
    }
    if (safe == 0) {
        cout << 0;
        return 0;
    }
    dfs( 0, 0 );
    if (mins == 1000000007) cout << -1;
    else cout << mins;
}