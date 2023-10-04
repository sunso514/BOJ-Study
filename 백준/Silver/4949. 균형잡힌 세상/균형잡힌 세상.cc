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


#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;


struct Balloon {
	int index, val;
};

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string a; 
		getline(cin, a);
		stack<int> sta;

		if (a == ".") break;

		bool check = true;

		for (int i = 0; i < a.length()-1; i++) {
			if (a[i] == '[') sta.push(0);
			else if (a[i] == '(') sta.push(1);

			else if (a[i] == ']') {
				if (sta.size() == 0) {
					check = false;
					break;
				}
				if (sta.top() == 0) {
					sta.pop();
				}
				else {
					check = false;
					break;
				}
			}
			else if (a[i] == ')') {
				if (sta.size() == 0) {
					check = false;
					break;
				}
				if (sta.top() == 1) {
					sta.pop();
				}
				else {
					check = false;
					break;
				}
			}
		}
		if (check == false) {
			cout << "no" << endl;
			continue;
		}
		if (sta.size() == 0) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}