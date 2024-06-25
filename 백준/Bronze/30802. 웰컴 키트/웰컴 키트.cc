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

int N, M;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

#define X dx[i] + loc.x
#define Y dy[i] + loc.y



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;

	int a[6] = { 0, };
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	
	int T, P;
	cin >> T >> P;
	
	int ans = 0;
	for(int i = 0; i < 6; i++){
		if (a[i] == 0) continue;
		ans += (a[i] + (T-1)) / T;
	}
	cout << ans << endl;

	cout << N / P << " " << N % P;
}