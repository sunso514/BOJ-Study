#include <iostream>
#include <algorithm>
#include <stack>
#define GB " "

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;
    stack<pair<int, int>> tow; // index, height

    int store_siz = 0;
    int now = 0;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        
        while (!tow.empty()) {
            if (tow.top().second >= a) {
                cout << tow.top().first << GB;
                break;
            }
            tow.pop();
        }
        if (tow.empty()) cout << 0 << " ";
        tow.push({ i + 1, a });
    }
}