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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string a; cin >> a;
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	cout << a;
}