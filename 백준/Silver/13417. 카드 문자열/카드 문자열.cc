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



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int TC; cin >> TC;
	while (TC--) {
		int N; cin >> N;
		deque<char> deq;
		
		char a; cin >> a;
		deq.push_back(a);

		for (int i = 1; i < N; i++) {
			cin >> a;
			if (deq.front() >= a) deq.push_front(a);
			else deq.push_back(a);
		}

		while (!deq.empty()) {
			cout << deq.front();
			deq.pop_front();
		}
		cout << "\n";
	}
}