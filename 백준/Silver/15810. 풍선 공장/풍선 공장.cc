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


int N, M;
vector<int> staffs;

long long checkG(long long tme) {
	long long bam = 0;
	FOR(i, N) bam += tme / staffs[i];
	return bam;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);


	cin >> N >> M;
	staffs.resize(N);

	FOR(i, N) cin >> staffs[i];
	sort(staffs.begin(), staffs.end());

	//long long mint = 1000000000001;


	long long left = 0;
	long long right = 1000000000001;
	long long mid;
	while (left < right) {

		mid = left + (right - left) / 2;
		long long ch = checkG(mid);

		if (ch < M) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
		//cout << left << " " << right << " " << mid << endl;
		//cout << ch << endl;


	}
	cout << right;
}