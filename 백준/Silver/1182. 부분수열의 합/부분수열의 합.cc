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

int N, M, T;
int res = 0;
vector<int> lst(20, 0);

void backtracking(int now, int sum) {
	if (now == N) return;
	if (sum + lst[now] == M) res++;

	backtracking(now + 1, sum + lst[now]);
	backtracking(now + 1, sum);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> lst[i];
	}
	backtracking(0, 0);
	cout << res;

} 