#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, L;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> L;
    vector<pair<int, int>> gp;
    
    FOR(i, N) {
        int a, b;
        cin >> a >> b;
        gp.push_back({ a, b });
    }

    sort(gp.begin(), gp.end());

    int count = 0;
    int x = 0;

    FOR(i, N) {
        if (x >= gp[i].second) continue;
        x = max(x, gp[i].first);

        while (x < gp[i].second) {
            count++;
            x += L;
        }
    }   

    cout << count;
}