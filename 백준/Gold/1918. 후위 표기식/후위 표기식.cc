
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




int main(void) {
	cin.tie(NULL);
	
	string ans = "";

	string sik;
	cin >> sik;


	stack<char> stk;
	for (int i = 0; i < sik.length(); i++) {
		
		char c = sik[i];

		if (c >= 'A' && c <= 'Z') ans += c;
		if (c == '(') stk.push(c);
		if (c == ')') {
			while (stk.top() != '(') {
				ans += stk.top();
				stk.pop();
			}
			stk.pop();
		}
		if (c == '+' || c == '-') {
			while (!stk.empty() && stk.top() != '(') {
				ans += stk.top();
				stk.pop();
			}
			stk.push(c);
		}
		if (c == '/' || c == '*') {
			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
				ans += stk.top();
				stk.pop();
			}
			stk.push(c);
		}
		//cout << i << " : " << ans << endl;
	}
	
	while (!stk.empty()) {
		ans += stk.top();
		stk.pop();
	}

	cout << ans << endl;
}
