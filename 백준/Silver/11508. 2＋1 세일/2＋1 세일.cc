#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> vec(N);
	FOR(i, N) cin >> vec[i];
	sort(vec.begin(), vec.end());

	long long ans = 0;
	int remove_ct = 0;

	FOR(i, vec.size()%3) ans += vec[i];
	for (int i = N - 1; i > (vec.size() % 3); i--) {
		if ((i + 1 - vec.size() % 3) % 3 != 1) ans += vec[i];
	}

	cout << ans;
}