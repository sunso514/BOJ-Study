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


struct Balloon {
	int index, val;
};

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	FOR(tc, N) {
		int A, B;
		cin >> A >> B;
		deque<pair<int, int>> que;
		vector<int> amo(10, 0);
		

		FOR(i, A) {
			int cost; cin >> cost;
			amo[cost]++;
			que.push_back({ cost, i });
		}

		int count = 1;
		
		while (!que.empty()) {
			pair<int ,int> now = que.front();
			bool check = true;
			for (int i = now.first + 1; i <= 9; i++) {
				if (amo[i] != 0) check = false;
			}

			if (check == false) {
				que.push_back(que.front());
				que.pop_front();
			}
			else {
				if (que.front().second == B) {
					cout << count << endl;
					break;
				}
				else {
					amo[que.front().first]--;
					que.pop_front();
					count++;
				}
			}
		}
	}


}