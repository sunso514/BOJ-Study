#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>

using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, time, broke;
	cin >> n >> time;
	int bstate[11] = { 0 };
	if (time > 0) {
		for (int i = 0; i < time; i++) {
			cin >> broke;
			bstate[broke] = 1;
		}
	}
	int res = abs(n - 100);
	int count = 0;
	for (int i = 0; i < 1000000; i++) {
		int nl = i;
		int length = 0;
		int no = i;
		if (i == 0) {
			if (bstate[i] == true) length = 0;
			else length = 1;
		}
		while (no > 0) {
			if (bstate[no % 10] == 1) {
				length = 0;
				no = -1;
			}
			else {
				no = no / 10;
				length += 1;
			}
		}
		if (length > 0) {
			int pressnum = abs(i - n);
			if (res > pressnum + length) res = pressnum + length;
		}
	}
	cout << res << "\n";
}
