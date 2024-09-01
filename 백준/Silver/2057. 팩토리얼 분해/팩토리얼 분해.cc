#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long fac[20];
	fac[0] = 1;
	for (int i = 1; i < 20; i++) {
		fac[i] = fac[i - 1] * i;
	}

	long long N; cin >> N;
	if (N == 0) {
		cout << "NO";
		return 0;
	}
	
	for (int i = 19; i >= 0; i--) {
		if (N >= fac[i]) {
			N -= fac[i];
		}
		if (N == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}