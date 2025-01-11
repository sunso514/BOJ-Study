#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> que;

	cin >> N;
	FOR(i, N) que.push(i + 1);
	
	while (true) {
		if (que.size() == 1) break;
		que.pop();

		if (que.size() == 1) break;
		que.push(que.front());
		que.pop();
	}
	cout << que.front();
}