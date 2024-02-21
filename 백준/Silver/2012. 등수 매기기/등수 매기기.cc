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

using namespace std;

bool oper(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> ac;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ac.push_back(a);
    }

    sort(ac.begin(), ac.end());

    long long sum = 0;
    FOR(i, N) {
        sum += abs((i + 1) - ac[i]);
    }
    cout << sum;


}


