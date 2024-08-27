#include <iostream>
#include <algorithm>
#include <stack>
#include <map>

#include <bitset>

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	map<string, bool> m;

	for (int i = 0; i < N; i++) {
		string a, b; cin >> a >> b;
		m[a] = (b == "enter");
	}

	stack<string> ans;
	for (auto i : m) {
		if (i.second == true) ans.push(i.first);
	}
	while(!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}
}