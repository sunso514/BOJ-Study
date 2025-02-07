#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	string S; cin >> S;
	
	vector<int> vec(27, 0);

	int nocheckidx = (N % 2 == 0) ? -1 : N / 2;
	for (int i = 0; i < N; i++) {
		if (nocheckidx == i) continue;
		vec[S[i] - 'a']++;
	}

	
	bool pass = true;
	for (int i = 0; i < 26; i++) {
		if (vec[i] % 2 != 0) {
            pass = false;
            break;
		}
	}
	(pass == true) ? cout << "Yes" : cout << "No";
}