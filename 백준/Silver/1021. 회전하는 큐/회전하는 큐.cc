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


int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> deq;
	cin >> N >> M;

	vector<int> check(N + 1);
	vector<int> lst;


	FOR(i, N) {
		deq.push_back(i + 1);
	}

	FOR(i, M) {
		int a; cin >> a;
		check[a] = true;
		lst.push_back(a);
	}

	int count = 0;


	FOR(tc, M) {

		int left, right;

		FOR(i, deq.size()) {
			if (deq[i] == lst[tc]) {
				left = i;
				right = deq.size() - i;
			}
		}

		if (left < right) {
			while (deq.front() != lst[tc]) {
				deq.push_back(deq.front());
				deq.pop_front();
				count++;

			}
		}
		else {
			while (deq.front() != lst[tc]) {
				deq.push_front(deq.back());
				deq.pop_back();
				count++;
			}
		}
		deq.pop_front();
	}
	
	cout << count;
}