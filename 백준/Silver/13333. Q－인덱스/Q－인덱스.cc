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

int N;

// k번 이상 인용된 논문이 k편 이상
bool check_fst(vector<int> &vec, int &q) {
	int count = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (vec[i] >= q) {
			count++;
		}
		if (count >= q) {
			return true;
		}
	}
	return false;
}

// 나머지 n-k편의 논문들 인용회수가 각각 k번 이하
bool check_sec(vector<int>& vec, int& q) {
	for (int i = 0; i < N - q; i++) {
		if (vec[i] > q) return false;
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	// Q 인덱스 가 0부터 확인, q는 k다
	for (int q = 0; q <= 1000; q++) {

		// k번 이상 인용된 논문이 k편 이상
		if (check_fst(vec, q) == false) continue;
		// 나머지 n-k편의 논문들 인용회수가 각각 k번 이하
		if (check_sec(vec, q) == false) continue;
		cout << q;
		return 0;
	}
}