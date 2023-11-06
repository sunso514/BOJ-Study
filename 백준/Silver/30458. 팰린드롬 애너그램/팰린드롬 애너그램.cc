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


#define X dx[i] + loc.x
#define Y dy[i] + loc.y



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	string S; cin >> S;
	
	vector<int> vec(27, 0);

	int nocheckidx = (N % 2 == 0) ? -1 : N / 2;
	for (int i = 0; i < N; i++) {
		if (nocheckidx == i) {
			continue;
		}
		vec[S[i] - 'a']++;
	}

	
	bool chance = true;
	bool pass = true;
	for (int i = 0; i < 26; i++) {
		//cout << vec[i] << " ";
		if (vec[i] % 2 != 0) {
			if (chance == true) {
				chance = false;
			}
			else {
				pass = false;
				break;
			}
		}
	}
	(pass == true) ? cout << "Yes" : cout << "No";
}