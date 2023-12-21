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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, C; cin >> R >> C;
    
    vector<string> board(R);
    FOR(i, R) cin >> board[i];

    string word = "";

    vector<string> ans;

    FOR(i, R) FOR(j, C) {
        if (board[i][j] != '#') {
            word.push_back(board[i][j]);
        }
        if (board[i][j] == '#' || j == C - 1) {
            if (word.length() > 1) ans.push_back(word);
            word = "";
        }
    }

    word = "";
    FOR(j, C) FOR(i, R) {
        if (board[i][j] != '#') {
            word.push_back(board[i][j]);
        }
        if (board[i][j] == '#' || i == R - 1) {
            if (word.length() > 1) ans.push_back(word);
            word = "";
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << ans[0];
}