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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, goal;
	cin >> N >> M >> goal;
	
	vector<vector<int>> act(N, vector<int>(M));
	vector<int> score(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> act[i][j];
		}
	}

	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			score[i] += act[i][j];
			if (score[i] >= goal) {
				cout << i + 1 << " " << j + 1;
				return 0;
			}
		}
	}

}