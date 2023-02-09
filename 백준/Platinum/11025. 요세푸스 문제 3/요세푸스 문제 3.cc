#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res = ((res + k - 1) % i) + 1;
    }
    cout << res;
}
