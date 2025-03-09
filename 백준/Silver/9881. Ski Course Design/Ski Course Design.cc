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
    
	int N, h[1000];

	cin >> N;
	for (int i = 0; i < N; i++) cin >> h[i];
	
	int ans = 9999999;
	for (int i = 0; i <= 100 - 17; i++) {
		int temp = 0;
		for (int j = 0; j < N; j++) {
			if (h[j] < i) temp += (i - h[j]) * (i - h[j]);
			if (h[j] > i + 17) temp += (h[j] - i - 17) * (h[j] - i - 17);
		}
		ans = min(ans, temp);
	}
	cout << ans << '\n';
}
