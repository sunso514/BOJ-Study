#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	vector<long long> sum(M + 1);

	int get;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		cin >> get;
		sum[j + 1] += get;
	}
	
	for (int i = 1; i < M + 1; i++) {
		sum[i] += sum[i - 1];
	}

	int range;
	cin >> range;

	long long maxV = -1;
	for (int i = 0; i + range <= M; i++) {
		maxV = max(maxV, sum[i + range] - sum[i]);
	}
	cout << maxV;
}