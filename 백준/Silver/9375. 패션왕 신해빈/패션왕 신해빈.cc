#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>

using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	string noj;

	for (int i = 0; i < n; i++) {
		int howmany;
		cin >> howmany;
		int code = 0;
		int gaesu[101] = { 0 };
		map<string, int> m;
		for (int j = 0; j < howmany; j++) {
			string getkey;
			cin >> noj >> getkey;
			if (m.find(getkey) != m.end()) {
				gaesu[m[getkey]]++;
			}
			else {
				m.insert({ getkey, code });
				gaesu[code]++;
				code++;
			}
		}
		int res = 1;
		for (int k = 0; k < code; k++) {
			res *= gaesu[k] + 1;
		}
		res--;
		cout << res << "\n";
	}

}