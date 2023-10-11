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
	vector<int> vec(N);
	
	FOR(i, N) cin >> vec[i];

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	FOR(i, N) cout << vec[i] << endl;
}