#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <deque>
#include <set>
#include <tuple>
#define test "test "
#define endl "\n"
#define GB " "

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
//string dir[4] = { "X", "A", "W", "D" };
string dir[4] = { "D", "X", "A", "W" };

bool voidcheck(int x, int y) {
    if (x > 30 || y > 30 || x < 0 || y < 0)return false;
    return true;
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<int>> graph(32, vector<int>(32, 0));
    vector<string> ans(505);

    for (int i = 1; i <= N; i++) {
        int a, b; cin >> a >> b;
        graph[a+15][b+15] = i;
    }
    int nowx = 15; 
    int nowy = 15;
    
    int direction = 0;
    int maxc = 1;


    string pathfind;
    
    while (true) {
        for (int db = 0; db < 2; db++) {
            for (int i = 0; i < maxc; i++) {

                nowx += dx[direction];
                nowy += dy[direction];
                if (voidcheck(nowx, nowy) == false) break;
                pathfind.append(dir[direction]);
                if (graph[nowx][nowy] != 0) {
                    string TMP = pathfind;
                    reverse(TMP.begin(), TMP.end());
                    ans[graph[nowx][nowy]] = TMP;
                }
                //cout << " / ";
            }
            direction = (direction + 1) % 4;
            if (voidcheck(nowx, nowy) == false) break;
        }
        //cout << endl;
        maxc += 1;
        if (voidcheck(nowx, nowy) == false) break;
    }

    for (int i = 1; i <= 500; i++) {
        //cout << test;
        if (ans[i].length() < 1) break;
        cout << ans[i] << endl;
    }

    //cout << pathfind;



}