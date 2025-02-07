
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

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;


bool checkS(int point, string N, string cmp) {
    for (int i = 0; i < cmp.length(); i++) {
        if (N[i + point] != cmp[i]) return false;
    }
    return true;
}


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M; cin >> N >> M;

    vector<vector<bool>> cant(N+1, vector<bool>(N+1, false));
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        cant[a][b] = true;
        cant[b][a] = true;
    }

    int count = 0;
    for (int i = 1; i <= N-2; i++) {
        for (int j = i + 1; j <= N-1; j++) {
            if (cant[i][j] == true) continue;
            for (int k = j + 1; k <= N; k++) {
                if (cant[i][k] == true) continue;
                if (cant[j][k] == true) continue;
                count++;
            }
        }
    }
    cout << count;
}
    