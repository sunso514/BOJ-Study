#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, C;
long long W;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> N >> C >> W;
	vector<int> trees(N, 0);

	int maxv = 0;
	FOR(i, N) {
		cin >> trees[i];
		maxv = max(maxv, trees[i]);
	}

	long long ans = 0;
	for (int L = 1; L <= maxv+1; L++) {
		
		long long tmp = 0;


		for (auto t_size : trees) {
			long long cost = 0;
			long long K = t_size / L;

			// 나누어 떨어지지 않았다면
			if (t_size % L != 0) cost = K * C;
			else cost = (K - 1) * C;
            
			if (K * W * L - cost > 0) tmp += K * W * L - cost;
			//cout << tmp << " ";
		}
		//cout << endl;
		ans = max(tmp, ans);
	}
	cout << ans;
} 