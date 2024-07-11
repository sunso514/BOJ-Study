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