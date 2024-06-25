#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;

	int a[6] = { 0, };
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	
	int T, P;
	cin >> T >> P;
	
	int ans = 0;
	for(int i = 0; i < 6; i++){
		if (a[i] == 0) continue;
		ans += (a[i] + (T-1)) / T;
	}
	cout << ans << endl;

	cout << N / P << " " << N % P;
}