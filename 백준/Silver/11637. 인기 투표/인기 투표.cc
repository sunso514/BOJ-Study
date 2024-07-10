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

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N, M;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

#define X dx[i] + loc.x
#define Y dy[i] + loc.y

string getZero(int N) {
	if (N < 10) {
		string tmp = "0";
		tmp.push_back(N + '0');
		return tmp;
	}
	return to_string(N);
}

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