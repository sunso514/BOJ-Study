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

#include <bitset>

#define test "test "
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

struct Location {
    int x, y, time;
};


vector<vector<vector<int>>> visit;
vector<vector<vector<int>>> mp;
queue<Location> que;

int dx[9] = { 1, 1, 1, -1, -1, -1, 0, 0, 0 };
int dy[9] = { 1, 0, -1, 1, 0, -1, 1, -1, 0 };

int bfs() {
    Location loc;

    while (!que.empty()) {
        loc = que.front();
        que.pop();
        
        if (mp[loc.x][loc.y][loc.time] == 1) continue;

        if (loc.x == 0 || loc.y == 7) {
            return 1;
        }

        FOR(i, 9) {
            if (X < 0 || Y < 0 || X >= 8 || Y >= 8) continue;
            if (mp[X][Y][loc.time] == 1 || visit[X][Y][loc.time] == 1) continue;
            que.push({ X, Y, min(10, loc.time+1) });
            visit[X][Y][loc.time] = true;
        }
    }
    return 0;
}

void settingMap(int y, int x) {
    int count = 0;
    for (int i = y; i < 8; i++) {
        mp[i][x][count] = 1;
        count++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    mp.resize(8, vector<vector<int>>(8, vector<int>(12)));
    visit.resize(8, vector<vector<int>>(8, vector<int>(12)));
    vector<string> tmp(8);
    FOR(i, 8) cin >> tmp[i];
    FOR(i, 8) FOR(j, 8) if (tmp[i][j] == '#') settingMap(i, j);

    que.push({ 7, 0, 0 });
    cout << bfs();
}