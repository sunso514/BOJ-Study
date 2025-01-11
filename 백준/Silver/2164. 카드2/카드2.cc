#include <iostream>
#include <algorithm>
#include <deque>


using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> deq;

	cin >> N;
	FOR(i, N) deq.push_back(i + 1);
	
	while (true) {
		if (deq.size() == 1) break;
		deq.pop_front();

		if (deq.size() == 1) break;
		deq.push_back(deq.front());
		deq.pop_front();
	}
	cout << deq.front();
}