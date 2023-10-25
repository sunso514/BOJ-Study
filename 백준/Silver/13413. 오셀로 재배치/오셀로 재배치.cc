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

int T, N;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	FOR(i, T) {
		cin >> N;
		string A, B;
		cin >> A >> B;
		int ned_a = 0, ned_b = 0;
		FOR(j, N) if (A[j] != B[j]) (A[j] == 'W') ? ned_b++ : ned_a++;
		cout << max(ned_b, ned_a) << endl;
	}
}