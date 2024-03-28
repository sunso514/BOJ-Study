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

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	int now = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int get; cin >> get;
		if (get == now) {
			ans++;
			now = (now + 1) % 3;
		}
	}
	cout << ans;

}