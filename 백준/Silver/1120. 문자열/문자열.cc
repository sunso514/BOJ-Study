
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
	
	string a, b;
	cin >> a >> b;
	int ans = 99999999;
	for(int i = 0; i < b.size() - a.size() + 1; i++){
		int count = 0;
		for (int j = i; j < i + a.size(); j++) {
			if (a[j-i] != b[j]) count++;
			//cout << a[j-i] << b[j] << " ";
		}
		ans = min(ans, count);
		//cout << count << endl;
	}
	cout << ans;
}
