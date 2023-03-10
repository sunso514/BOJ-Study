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
#define test "test "
#define endl "\n"

using namespace std;

int N, M;

struct Location {
    int x, depth;
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    vector<int> lists;
    vector<int> sums(N, 0);

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        lists.push_back(a);
        sums.push_back(a);
    }

    sums[0] = lists[0];
    for (int i = 1; i < N; i++) {
        sums[i] = lists[i] + sums[i - 1];
    }

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        if (a == 1) cout << sums[b - 1 ];
        else {
           cout << sums[b - 1] - sums[a - 2];
        }
        cout << endl;
    }
    


}