#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;

	vector<int> light(M);
	vector<vector<int>> connection(N, vector<int>(0));
	for (int i = 0; i < N; i++) {
		int tm; cin >> tm;
		for (int j = 0; j < tm; j++) {
			int num; cin >> num;
			light[num-1]++;
			
			connection[i].push_back(num - 1);
		}
	}

	for (int i = 0; i < N; i++) {
		bool check = true;
		for (auto j : connection[i]) {
			if (light[j] - 1 <= 0) check = false;
		}
		if (check == true) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}