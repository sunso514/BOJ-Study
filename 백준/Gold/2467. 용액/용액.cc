#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N;
int lists[100003];
int value = 2000000003;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> lists[i];
	}
	sort(lists, lists + N);
	int res_l;
	int res_r;

	int left = 0;
	int right = N-1;

	while (left < right) {
		int tmp = abs(lists[left] + lists[right]);
		if (tmp < value) {
			res_l = lists[left];
			res_r = lists[right];
			value = tmp;
		}
		if (tmp == 0) break;
		
		if (lists[left] + lists[right] < 0) left++;
		else right--;
	}
	cout << res_l << " " << res_r;
}