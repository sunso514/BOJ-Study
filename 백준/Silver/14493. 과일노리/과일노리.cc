#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int T = 0;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		int checkT = T % (A + B);
		if (checkT < B) {
			T += B - checkT;
		}
		T++;
	}
	cout << T;
}