#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n = 1000;
	cin >> n;

	vector<bool> vec(7400000);
	vec[1] = true;
	for (int i = 2; i <= sqrt(7400000); i++) {
		if (vec[i]) continue;
		for (int j = i + i; j <= 7400000; j += i) vec[j] = true;
	}
	int count = 0;
	for (int i = 2; i <= 7400000; i++) {
		if (!vec[i]) {
			count++;
			if (count == n) {
				cout << i;
				return 0;
			}
		}
	}



}