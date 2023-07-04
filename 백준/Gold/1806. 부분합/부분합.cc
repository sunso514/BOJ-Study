#include <iostream>
#include <algorithm>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, s_proc;
int lists[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	
	cin >> N >> s_proc;
	
	for (int i = 0; i < N; i++) cin >> lists[i];

	int now_sum = lists[0];
	int right = 0;
	int min_size = 100005;

	for (int left = 0; left < N; left++) {
		while (right < N && now_sum < s_proc) {
			right++;
			if (right != N) now_sum += lists[right];
		}
		if (right == N) break;
		min_size = min(min_size, right - left + 1);
		
		now_sum -= lists[left];
	}
	if (min_size == 100005) min_size = 0;
	cout << min_size;
}