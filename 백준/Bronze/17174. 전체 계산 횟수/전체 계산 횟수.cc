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



int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	

	int N, M;
	cin >> N >> M;
	int ans = N;
	while (N >= M) {
		N /= M;
		ans += N;
		//cout << N << " " << M << endl;
	}
	cout << ans;

	return 0;
}
