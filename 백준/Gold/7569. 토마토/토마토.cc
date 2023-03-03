#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>



#define test "test "
#define endl "\n"

using namespace std;
#define X l.x + dx[i]
#define Y l.y + dy[i]
#define Z l.z + dz[i]

const int dx[6] = { -1, 1, 0, 0,0,0 };
const int dy[6] = { 0, 0, -1, 1,0,0 };
const int dz[6] = { 0, 0,0,0, -1, 1 };

int N, M, H;

vector<vector<vector<int>>> graph; // 노드
vector<vector<vector<int>>> depth; // 길이 ( 날짜 )
vector<vector<vector<bool>>> visit;


struct Loc {
    int x, y, z;
};
queue<Loc> que;
int day = 0;
void bfs() {

    Loc l;
    while (!que.empty()) {
        l = que.front();
        que.pop();
        for (int i = 0; i < 6; i++) {
            if (X < 0 || Y < 0 || Z < 0 || X >= H || Y >= M || Z >= N) {
                continue;
            }
            if (!visit[X][Y][Z] && graph[X][Y][Z] == 0) {

                que.push({ X , Y, Z });
                visit[X][Y][Z] = true;
                depth[X][Y][Z] = depth[l.x][l.y][l.z] + 1;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> H;
    graph.resize(H, vector<vector<int>>(M, vector<int>(N)));
    depth.resize(H, vector<vector<int>>(M, vector<int>(N)));
    visit.resize(H, vector<vector<bool>>(M, vector<bool>(N)));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1) que.push({ i, j, k });
            }         
        }
    }
    if (que.size() == H * M * N) {
        cout << 0;
        return 0;
    }
    bfs();
    int day = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (graph[i][j][k] == 0 && !visit[i][j][k]) {
                    cout << -1;
                    return 0;
                }
                if (day < depth[i][j][k]) day = depth[i][j][k];
            }
        }
    cout << day;
}