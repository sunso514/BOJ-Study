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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		string N; cin >> N;

		int ans = 0;
		bool check[10] = { false };
		for (auto c : N) {
			if (check[c - '0'] == false) {
				ans++;
				check[c - '0'] = true;
			}
		}
		cout << ans << endl;

	}
}