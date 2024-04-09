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

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, A, B, C; cin >> N >> A >> B >> C;
	
	vector<int> kcals(N);
	for (int i = 0; i < N; i++) {
		cin >> kcals[i];
	}
	sort(kcals.begin(), kcals.end());
	reverse(kcals.begin(), kcals.end());
	
	int ans = C / A;
	int price = A;
	int kcal = C;
	for (int i = 0; i < N; i++) {
		price += B;
		kcal += kcals[i];
		if (ans < kcal/price) {
			ans = kcal/price;
		}
	}
	cout << ans;
}