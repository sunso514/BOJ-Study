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

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	int countB = 0;
	int countR = 0;
	char now = '0';

	string name; cin >> name;

	for (int i = 0; i < N; i++) {
		if (now != name[i]) {
			(name[i] == 'B') ? countB++ : countR++;
			now = name[i];
		}
	}
	cout << 1 + min(countB, countR);

} 