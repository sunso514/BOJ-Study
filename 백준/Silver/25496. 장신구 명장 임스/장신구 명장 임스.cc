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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, P; cin >> P >> N;

	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	int count = 0;
	for (auto i : vec) {
		if (P >= 200) break;
		count++;
		P += i;
	}
	cout << count;

}