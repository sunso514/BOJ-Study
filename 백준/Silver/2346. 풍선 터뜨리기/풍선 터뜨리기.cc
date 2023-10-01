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

	deque<Balloon> deq;
	cin >> N;

	FOR(i, N) {
		int a; cin >> a;
		deq.push_back({ i + 1 , a });
	}

	while (true) {
		cout << deq.front().index << " ";
		Balloon a = deq.front();
		deq.pop_front();
		if (deq.empty()) break;


		if (a.val > 0) {
			FOR(i, a.val - 1){
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else {
			FOR(i, abs(a.val)) {
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
	}


}