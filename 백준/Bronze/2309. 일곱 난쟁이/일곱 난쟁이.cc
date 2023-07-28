#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> nan(9);
	int tmp = 0;
	for (int i = 0; i < 9; i++) {
		cin >> nan[i];
		tmp += nan[i];
	}
	sort(nan.begin(), nan.end());

	int noa = -1, nob = -1;

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (tmp - nan[i] - nan[j] == 100) {
				noa = nan[i];
				nob = nan[j];
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (nan[i] != noa && nan[i] != nob) cout << nan[i] << endl;
	}
} 