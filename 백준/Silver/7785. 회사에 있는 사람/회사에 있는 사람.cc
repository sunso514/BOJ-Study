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


pair<int, int> get_letters(string N) {
	int small = 0;
	int big = 0;
	for (auto i : N) {
		if (i >= 'a' && i <= 'z') small++;
		if (i >= 'A' && i <= 'Z') big++;
	}
	return { small, big };
}





int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	vector<int> names;
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