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

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

using namespace std;

int R, C;

struct Location {
    int x, y, time;
};

vector<string> grid;
vector<vector<int>> visit;
vector<vector<int>> graph;

queue<Location> que;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    vector<int> road(N+1, 0);
    vector<int> dp(N + 1, 1000000007);
    for (int i = 0; i < N; i++) {
        cin >> road[i];
    }

    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] == 1000000007) continue;
        for (int j = i + 1; j < min(N, i+1001); j++) {
            int power = (j - i) * (1 + abs(road[i] - road[j]));
            if (dp[j] > power && power <= K) {
                dp[j] = power;
            }
        }
    }
    /*FOR(i, N) {
        cout << dp[i] << " ";
    }
    cout << endl;
    */
    if (dp[N - 1] == 1000000007) {
        cout << "NO";
    }
    else cout << "YES";
}