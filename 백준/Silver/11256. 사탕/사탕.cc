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

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int J, N; cin >> J >> N;
		vector<int> box(N);
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			box[i] = a * b;
		}
		sort(box.begin(), box.end(), compare);
		int ans = 0;
		for (auto size : box) {
			ans++;
			J -= size;
			if (J <= 0) {
				break;
			}
		}
		cout << ans << endl;
	}
}