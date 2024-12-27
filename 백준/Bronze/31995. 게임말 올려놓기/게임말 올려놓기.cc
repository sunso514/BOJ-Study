
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

int N; 



int main(void) {
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    if (N == 1 || M == 1) cout << 0;
    else cout << (N - 1) * (M - 1) * 2;
}