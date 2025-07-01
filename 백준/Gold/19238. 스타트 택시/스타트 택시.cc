#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000009

int N, M;
long long oil;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct loc {
    int x, y, depth;
};

struct tile {
    int passno = -1;
    set<int> destno;
};

vector<vector<tile>> field;

int bfs(vector<vector<int>> wallInfo, int sx, int sy) {
    queue<loc> que;
    que.push({sx, sy, 0});
    int carried = 0;

    vector<vector<int>> visit(N, vector<int>(N));

    while (carried < M) {
        int passno = INF;
        loc passLoc = {-1, -1, INF};

        FOR(i, N) FOR(j, N) visit[i][j] = wallInfo[i][j];
        visit[sx][sy] = true;

        // 시작 지점에 승객이 있다면
        if (field[sx][sy].passno != -1) {
            passno = field[sx][sy].passno;
            passLoc = {sx, sy, 0};
        } else {
            // BFS로 최단거리 승객 찾기
            queue<loc> tempQ;
            tempQ.push({sx, sy, 0});

            while (!tempQ.empty()) {
                loc now = tempQ.front();
                tempQ.pop();

                if (now.depth > passLoc.depth) break;

                if (field[now.x][now.y].passno != -1) {
                    if (now.depth < passLoc.depth ||
                        (now.depth == passLoc.depth && now.x < passLoc.x) ||
                        (now.depth == passLoc.depth && now.x == passLoc.x && now.y < passLoc.y)) {
                        passLoc = now;
                        passno = field[now.x][now.y].passno;
                    }
                }

                FOR(d, 4) {
                    int nx = now.x + dx[d], ny = now.y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if (visit[nx][ny]) continue;
                    visit[nx][ny] = true;
                    tempQ.push({nx, ny, now.depth + 1});
                }
            }
        }

        if (passno == INF) return -1;

        // 이동 후 연료 소모
        oil -= passLoc.depth;
        if (oil < 0) return -1;

        field[passLoc.x][passLoc.y].passno = -1;

        // 목적지까지 이동
        FOR(i, N) FOR(j, N) visit[i][j] = wallInfo[i][j];
        visit[passLoc.x][passLoc.y] = true;

        queue<loc> destQ;
        destQ.push({passLoc.x, passLoc.y, 0});
        bool arrived = false;

        while (!destQ.empty()) {
            loc now = destQ.front();
            destQ.pop();

            if (field[now.x][now.y].destno.count(passno)) {
                oil -= now.depth;
                if (oil < 0) return -1;
                oil += now.depth * 2;

                field[now.x][now.y].destno.erase(passno);
                que = queue<loc>();
                que.push({now.x, now.y, 0});
                sx = now.x; sy = now.y;
                arrived = true;
                break;
            }

            FOR(d, 4) {
                int nx = now.x + dx[d], ny = now.y + dy[d];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (visit[nx][ny]) continue;
                visit[nx][ny] = true;
                destQ.push({nx, ny, now.depth + 1});
            }
        }

        if (!arrived) return -1;
        carried++;
    }
    return oil;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> oil;
    vector<vector<int>> visit(N, vector<int>(N));
    field.resize(N, vector<tile>(N));
    FOR(i, N) FOR(j, N) cin >> visit[i][j];

    int sx, sy; cin >> sx >> sy;

    for (int i = 1; i <= M; i++) {
        int x, y, gx, gy;
        cin >> x >> y >> gx >> gy;
        field[x - 1][y - 1].passno = i;
        field[gx - 1][gy - 1].destno.insert(i);
    }

    cout << bfs(visit, sx - 1, sy - 1);
}
