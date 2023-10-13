


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

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	FOR(i, N) {
		vector<int> vec(5);
		int sum = 0;
		FOR(j, 5) {
			cin >> vec[j];
			sum += vec[j];
		}
		sort(vec.begin(), vec.end());
		if (vec[3] - vec[1] >= 4) cout << "KIN";
		else cout << sum - vec[0] - vec[4];
		cout << endl;
	}
}