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


int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	while (true) {
		int a;
		cin >> a;
		if (a == 0) break;
		for (int i = 0; i < a; i++) {
			for (int j = a - i-1; j < a; j++) {
				cout << "*";
			}
			cout << endl;
		}
	}

}
