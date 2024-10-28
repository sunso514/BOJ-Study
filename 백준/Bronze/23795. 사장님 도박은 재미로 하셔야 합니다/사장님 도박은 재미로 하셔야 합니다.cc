
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
	
	int ans = 0;
	while (1) {
		int N; cin >> N;
		if (N == -1) break;
		ans += N;
	}
	cout << ans;
}
