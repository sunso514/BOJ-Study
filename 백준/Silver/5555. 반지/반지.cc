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
	
	string goal;
	cin >> goal;

	int N;
	cin >> N;

	int ans = 0;
	for (int tc = 0; tc < N; tc++) {
		string get; cin >> get;
		for (int i = 0; i < 10; i++) {
			int count = 0;
			for (int j = 0; j < goal.length(); j++) {
				if (goal[j] == get[(i + j) % 10]) {
					count++;
				}
				else break;
			}
			if (count == goal.length()) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
}