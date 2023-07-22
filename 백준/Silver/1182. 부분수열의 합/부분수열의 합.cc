#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int res = 0;
int lst[20];

void backtracking(int now, int sum) {
	if (now == N) return;
	if (sum + lst[now] == S) res++;

	backtracking(now + 1, sum + lst[now]);
	backtracking(now + 1, sum);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> lst[i];

	backtracking(0, 0);
	cout << res;
} 