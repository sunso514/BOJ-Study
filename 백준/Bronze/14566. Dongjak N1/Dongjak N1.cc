#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	vector<int> bus(N);
	vector<int> diff(N-1);

	for (int i = 0; i < N; i++) {
		cin >> bus[i];
	}
	sort(bus.begin(), bus.end());
	
	for (int i = 0; i < N - 1; i++) {
		diff[i] = bus[i + 1] - bus[i];
	}

	sort(diff.begin(), diff.end());
	int minV = diff[0];
	int count = 0;
	for (int i = 0; i < N - 1; i++) {
		if (minV != diff[count]) break;
		count++;
	}
	cout << minV << " " << count;

}