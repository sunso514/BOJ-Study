
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
#include <iomanip>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)
#define INF 1000000009

using namespace std;

int N, M;

struct loc {
    int x, y;
    bool operator<(const loc& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

// 상 우 하 좌 U R D L
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


bool check_same(loc& a, loc& b) {
    return (a.x == b.x && a.y == b.y);
}

loc find_parent(vector<vector<loc>>& parent, loc x) {
    if (check_same(parent[x.x][x.y], x)) return x;
    return parent[x.x][x.y] = find_parent(parent, parent[x.x][x.y]);  
}

bool union_nodes(vector<vector<loc>>& parent, loc x, loc y) {
    loc px = find_parent(parent, x);
    loc py = find_parent(parent, y);
    if (check_same(px, py)) return false; // 같은 집합이다.
    parent[py.x][py.y] = px;  
    return true;
}

void bfs(vector<vector<int>> &graph, vector<vector<int>>& visit, vector<vector<loc>>& parent,  int sx, int sy) {
    queue<loc> que;

    que.push({ sx, sy });
    visit[sx][sy] = true;

    while (!que.empty()) {
        loc tmp = que.front();
        que.pop();

        int next_x = tmp.x + dx[graph[tmp.x][tmp.y]];
        int next_y = tmp.y + dy[graph[tmp.x][tmp.y]];
        if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
        union_nodes(parent, { tmp.x, tmp.y }, { next_x, next_y });
        if (visit[next_x][next_y] == false) {
            visit[next_x][next_y] = true;
            que.push({ next_x, next_y });
        }


    }


}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(M));
    vector<vector<int>> visit(N, vector<int>(M, false));
    vector<vector<loc>> parent(N, vector<loc>(M));

    string dirs = "URDL";
    for (int i = 0; i < N; i++) {
        string get; cin >> get;
        for (int j = 0; j < M; j++) {

            // 부모 본인으로 설정
            parent[i][j] = { i, j };

            // 그래프에 방향 넣어주기
            for (int k = 0; k < 4; k++) {
                if (dirs[k] == get[j]) graph[i][j] = k;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j] == false) {
                bfs(graph, visit, parent, i, j);
            }
        }
    }
    


    set<loc> st;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            loc test = find_parent(parent, { i, j });
            st.insert(test);

            //cout << "{ " << test.x << ", " << test.y << " } ";

            //cout << "{ " << parent[i][j].x << ", " << parent[i][j].y << " } ";
        }
        //cout << endl;
    }
    
    cout << st.size();

}

