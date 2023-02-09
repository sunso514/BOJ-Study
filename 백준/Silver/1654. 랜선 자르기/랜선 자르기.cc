#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int time, need;
	cin >> time >> need;
	vector<int> list(time);

	long long min = 0, max = 1;
	for (int i = 0; i < time; i++) {
		cin >> list[i];
		if (list[i] > max) max = list[i];
	}
	max++;
	long long mid = (min + max) / 2;
	int lamt = 0;
	while(min+1 < max) {
		lamt = 0;
		for (int i = 0; i < time; i++) {
			
			lamt += (list[i] / mid);
		}

		if (lamt >= need) {
			min = mid;
			mid = (min + max) / 2;
		}
		else if (lamt < need) {
			max = mid;
			mid = (min + max) / 2;
		}
	}
	cout << mid;
}