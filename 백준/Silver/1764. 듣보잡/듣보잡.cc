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

	map<string, int> map;
	int n, m;
	cin >> n >> m;
	vector<string> list;
	for (int i = 0; i < n; i++) {
		string insert;
		cin >> insert;
		map.insert({ insert, i });
	}
	int count = 0;
	for (int i = 0; i < m; i++) {
		string insert;
		cin >> insert;
		if (map.find(insert) != map.end()) {
			list.push_back(insert);
			count++;
		}
	}
	cout << count << "\n";
	sort(list.begin(), list.end());
	for (int i = 0; i < count; i++) {
		cout << list[i] << "\n";
	}
}
