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

	map<string, string> map;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string insert, password;
		cin >> insert;
		cin >> password;
		map.insert({ insert, password });
	}
	for (int i = 0; i < m; i++) {
		string insert;
		cin >> insert;
		if (map.find(insert) != map.end()) {
			cout << map[insert] << "\n";
		}
	}
}
