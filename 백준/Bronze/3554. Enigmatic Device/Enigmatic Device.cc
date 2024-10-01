
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

	long long N; cin >> N;
	vector<long long> vec(N);
	FOR(i, N) cin >> vec[i];

	int T; cin >> T;
	for (int c = 0; c < T; c++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		
		if (cmd == 1) {
			for (int i = a - 1; i < b; i++) {
				vec[i] = vec[i] * vec[i] % 2010;
			}
		}
		else {
			int ans = 0;
			for (int i = a - 1; i < b; i++) {
				ans += vec[i];
			}
			cout << ans << endl;
		}
	
		
	}

}
