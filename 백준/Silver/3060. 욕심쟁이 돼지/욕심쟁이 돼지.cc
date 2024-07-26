#include <iostream>
#include <algorithm>

using namespace std;

bool able(const long long * pig, long long& limit) {
	long long sum = 0;
	for (int i = 0; i < 6; i++) sum += pig[i];
	if (sum <= limit) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		long long N; cin >> N;
		long long pig[6] = { 0, };
		long long tmp[6] = { 0, };
		for (int i = 0; i < 6; i++) cin >> pig[i];

		int day = 0;
		while (true) {
			day++;
			if (able(pig, N) == false) break;
			for (int i = 0; i < 6; i++) {
				tmp[i] = pig[i];
			}
			for (int i = 0; i < 6; i++) {
				for (int j = 1; j <= 5; j += 2) {
					pig[i] += tmp[(i + j) % 6];
				}
			}
		}
		cout << day << "\n";
	}

}