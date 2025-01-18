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

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long N;    
    cin >> N;

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        long long a; cin >> a;
        sum += a;
    }
    cout << sum - N * (N - 1) / 2;
}
    