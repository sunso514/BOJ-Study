#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		vector<int> vote(N);
		int sum = 0;
		int winner = -1;
		int score = 0;
		for (int j = 0; j < N; j++) {
			int sc; cin >> sc;
			sum += sc;
			if (sc > score) {
				winner = j + 1;
				score = sc;
			}
			else if (sc == score) {
				winner = -1;
			}
		}

		if (winner == -1) cout << "no winner\n";
		else if (sum / 2 < score) cout << "majority winner " << winner << "\n";
		else cout << "minority winner " << winner << "\n";
	}
	
}