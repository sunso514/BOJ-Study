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
	  

	//for (int i = 0; i < M + 1; i++) {
	//	cout << sum[i] << " ";
	//}
	//cout << endl;

	long long maxV = -1;
	for (int i = 0; i + range <= M; i++) {
		maxV = max(maxV, sum[i + range] - sum[i]);
	}
	cout << maxV;
}