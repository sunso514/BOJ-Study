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


int Rev(int N) {
	string tmp = to_string(N);

	int ans = 0;
	for (int i = 0; i < tmp.length(); i++) {
		ans += (tmp[i] - '0') * pow(10, i);
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B;
	cin >> A >> B;
	cout << Rev(Rev(A) + Rev(B));
}