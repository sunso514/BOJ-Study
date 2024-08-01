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
	for (int tc = 1; tc <= T; tc++) {
		int N; cin >> N;

		bool check[10] = { 0 };
		int count = 0;

		int i;
		for (i = 1; i < 100; i++) {
			string tmp = to_string(N * i);
			for (auto c : tmp) {
				if (check[c - '0'] == 0) {
					check[c - '0'] = 1;
					count++;
				}
			}
			if (count == 10) break;
		}
		cout << "Case #" << tc << ": ";
		if (count == 10) cout << i*N << '\n';
		else cout << "INSOMNIA\n";
	}
}