#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, M;

vector<vector<int>> bigger;
vector<vector<int>> smaller;
vector<int> visit;

int countv = 0;

void dfs(int loc, bool big) {
    for (auto x : (big == true) ? bigger[loc] : smaller[loc]){
        if (!visit[x]) {
            visit[x] = true;
            countv++;
            dfs(x, big);
        }
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    int mid = (N + 1) / 2;

    bigger.resize(N+1, vector<int>());
    smaller.resize(N+1, vector<int>());
    visit.resize(N + 1);

    FOR(i, M) {
        int a, b; cin >> a >> b;
        bigger[b].push_back(a);
        smaller[a].push_back(b);
    }


    int res = 0;

    for (int i = 1; i <= N; i++) {
        countv = 0;
        for (int t = 1; t <= N; t++) visit[t] = false;
        dfs(i, true);
        if (countv >= mid) {
            res++;
            continue;
        }
        countv = 0;
        for (int t = 1; t <= N; t++) visit[t] = false;
        dfs(i, false);
        if (countv >= mid) res++;
    }
    cout << res;
}