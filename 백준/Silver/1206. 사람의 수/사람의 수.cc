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
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	vector<int> lst(N);
	FOR(i, N) {
		string a; cin >> a;
		if (a == "10.000") {
			lst[i] = 10000;
			continue;
		}
		int res = (a[0] - '0') * 1000 + stoi(a.substr(2, a.length() - 1));
		lst[i] = res;
	}
	for (int i = 1; i <= 1000; i++) {
		bool toggle = true;
		for (auto goal : lst) {
			for (int people = 0; people <= i*10; people++) {
				int check = (1000 * people) / i ;
				if (check == goal) break;
				if (check > goal || people == i*10) {
					toggle = false;
					break;
				}
			}
			if (toggle == false) break;
		}
		if (toggle == true) {
			cout << i;
			return 0;
		}
	}
} 