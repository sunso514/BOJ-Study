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
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, K, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K >> M;
	bool reversal = false;
	int count = 0;
	deque<int> deq;

	FOR(i, N) deq.push_back(i + 1);

	while (!deq.empty()) {
		count++;
		int kill = K % deq.size();
		if (kill == 0) kill = K;
		for (int i = 0; i < kill - 1; i++) {
			if (reversal == false) {
				deq.push_back(deq.front());
				deq.pop_front();
			}
			else {
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}

		if (reversal == false) cout << deq[0];
		else cout << deq[deq.size() - 1];
		cout << endl;


		//cout << "Reverse : " << reversal << endl;
		if (reversal == false) deq.pop_front();
		else deq.pop_back();
		//FOR(i, deq.size()) cout << deq[i] << " ";
		//cout << endl;
		if (count == M) {
			reversal = !reversal;
			count = 0;
		}
		
	}
}