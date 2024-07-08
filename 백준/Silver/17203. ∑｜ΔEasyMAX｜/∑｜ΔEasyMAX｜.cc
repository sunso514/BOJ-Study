#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q;
	cin >> N >> Q;

	vector<int> vec(N);
	vector<int> change(N);
	vector<int> hap(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	for (int i = 1; i < N; i++) {
		change[i] = abs(vec[i] - vec[i - 1]);
		hap[i] = change[i] + hap[i - 1];
	}

	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (a >= b) cout << 0 << "\n";
		else cout << hap[b] - hap[a] << "\n";

	}

}