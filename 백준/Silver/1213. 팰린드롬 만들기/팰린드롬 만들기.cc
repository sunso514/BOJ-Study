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
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, C;
long long W;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> alp(26, 0);

	// 알파벳 개수 체크
	string name;
	cin >> name;
	FOR(i, name.length()) alp[name[i] - 'A']++;

	deque<char> ans;

	char hol = '0';
	for (int i = 25; i >= 0; i--) {
		if (alp[i] == 0) continue;
		if (alp[i] % 2 == 0) {
			FOR(j, alp[i] / 2) ans.push_front(i + 'A');
		}
		else {
			if (hol != '0') {
				cout << "I'm Sorry Hansoo";
				exit(0);
			}
			else {
				hol = i + 'A';
				FOR(j, alp[i] / 2) ans.push_front(i + 'A');
			}
		}
	}
	int siz = ans.size();
	if (hol != '0') ans.push_back(hol);
	for(int i = siz-1; i >= 0; i--) {
		ans.push_back(ans[i]);
	}


	FOR(i, ans.size()) cout << ans[i];
} 