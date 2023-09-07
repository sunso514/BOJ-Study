#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <deque>
#include <set>
#include <tuple>
#define test "test "
#define endl "\n"
#define GB " "

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)
int N, P;

int total = 0;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int get;
	int ans = 0;
	FOR(i, N) {

		int one = 0;
		int two = 0;

		int oneMTE = 0;
		int twoMTE = 0;

		int last = 0;

		FOR(j, M){
			cin >> get;

			if (get == 1 && last != 1) {
				one++;
				last = 1;
			}
			else if (get == 2 && last != 2) {
				last = 2;
				two++;
			}
			else if (get == 0 && last != 0) {
				last = 0;
				if (one > 0 || two > 0) {
					if (one > 0 && two > 0) {
						ans += 1 + min(one, two);
					}
					else ans += max(one, two);
					one = 0;
					two = 0;
				}
			}
			//cout << ans << endl;
		}
		if (one > 0 || two > 0) {
			if (one > 0 && two > 0) {
				ans += 1 + min(one, two);
			}
			else ans += max(one, two);
		}
	}

	cout << ans;
}