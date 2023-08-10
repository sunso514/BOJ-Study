#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)


int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int count = 0;

    vector<int> goal(N);
    vector<int> now(N);
    FOR(i, N) cin >> goal[i];

    FOR(i, N) {
        if (now[i] != goal[i]) {
            count++;
            now[i] = !now[i];
                
            if (i + 1 < N) now[i+1] = !now[i+1];
            if (i + 2 < N) now[i+2] = !now[i+2];
        }
        //FOR(i, N) cout << now[i] << " ";
        //cout << endl;
    }
    cout << count;
}