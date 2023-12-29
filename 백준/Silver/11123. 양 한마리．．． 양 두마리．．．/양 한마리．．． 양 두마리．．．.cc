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

#define test "test "
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int H, W;

vector<string> board(H);
vector<vector<int>> visit;

void dfs(int x, int y) {
   
    for (int i = 0; i < 4; i++) {
        int tmp_x = dx[i] + x;
        int tmp_y = dy[i] + y;

        if (tmp_x < 0 || tmp_y < 0 || tmp_x >= H || tmp_y >= W) continue;
        if (visit[tmp_x][tmp_y] == true || board[tmp_x][tmp_y] == '.') continue;

        visit[tmp_x][tmp_y] = true;
        dfs(tmp_x, tmp_y);
    }

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        cin >> H >> W;

        visit.clear();
        board.clear();
        
        visit.resize(H, (vector<int>(W, 0)));

        for (int i = 0; i < H; i++) {
            string get;
            cin >> get;
            board.push_back(get);
        }

        int count = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (board[i][j] == '#' && visit[i][j] == false) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << endl;
    }

}