#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	vector<double> leak(N);
	FOR(i, N) cin >> leak[i];
	sort(leak.begin(), leak.end());

	int ans = 0;

	int point = 0;
	double tape = leak[point] - 0.5;
	while (true) {
		
		// 테이프를 붙여야할 때까지 막 붙인다.
		while (tape < leak[point] + 0.5) {
			tape += M;
			//cout << "T : " << tape << endl;
			ans++;
		}
		point++;
		if (point == N) break;
		// 현재 건너뛰어야 할 경우
		if (leak[point] - 0.5 > tape) {
			tape = leak[point] - 0.5;
		}
	}
	cout << ans;
}