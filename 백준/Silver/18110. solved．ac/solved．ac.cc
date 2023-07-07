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

	double N , M;



	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);

		cin >> N;
		if (N == 0) {
			cout << 0;
			return 0;
		}
		deque<int> vec;

		for (int i = 0; i < N; i++) {
			cin >> M;
			vec.push_back(M);
		}
		sort(vec.begin(), vec.end());

		int percent = round(vec.size() * 0.15);
		for (int i = 0; i < percent; i++) {
			vec.pop_front();
			vec.pop_back();
		}

		double res = 0;
		for (int i = 0; i < vec.size(); i++) res += vec[i];
		res = round(res / vec.size());

		cout << res;

	}