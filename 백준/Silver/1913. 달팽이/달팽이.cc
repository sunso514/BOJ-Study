#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<vector<int>> roll;
int N, K;

bool checkPass(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) return false;
    if (roll[x][y] != 0) return false;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;

    roll.resize(N, vector<int>(N));

    int dir = 0;
    
    int nowx = 0;
    int nowy = 0;
    pair<int, int> answer = { 0, 0 };

    int count = N * N;
    while (true)
    {
        roll[nowx][nowy] = count;
        if (checkPass(nowx+dx[dir], nowy+dy[dir]) != true) dir = (dir + 1) % 4;
        if (count == K) {
            answer.first = nowx + 1;
            answer.second = nowy + 1;
        }
        nowx += dx[dir];
        nowy += dy[dir];
        count--;
        if (count == 0) break;
    }

    FOR(i, N) {
        FOR(j, N) cout << roll[i][j] << " ";
        cout << endl;
    }
    cout << answer.first << " " << answer.second;
}