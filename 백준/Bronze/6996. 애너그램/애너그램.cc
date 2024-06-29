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

int N, M;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

#define X dx[i] + loc.x
#define Y dy[i] + loc.y

bool isAnagrams(string a, string b) {
	vector<int> check(26, 0);
	if (a.length() != b.length()) return false;

	for (int i = 0; i < a.length(); i++) {
		check[a[i] - 'a']++;
	}
	for (int i = 0; i < b.length(); i++) {
		//cout << a[i] - 'a' << " ";
		if (check[b[i] - 'a'] > 0) check[b[i] - 'a']--;
		else return false;
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	for (int tc = 0; tc < N; tc++) {
		string a, b;
		cin >> a >> b;
		cout << a << " & " << b << " are ";
		if (isAnagrams(a, b) == false) {
			cout << "NOT ";
		}
		cout << "anagrams.\n";
	}
}