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

	vector<double> drinks(N);
	FOR(i, N) cin >> drinks[i];

	sort(drinks.begin(), drinks.end());
	FOR(i, N-1) {
		drinks[N - 1] += drinks[i] / 2;
	}

	cout << drinks[N - 1];


}