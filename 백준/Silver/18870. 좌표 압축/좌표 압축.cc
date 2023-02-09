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

	map<int, int> map;
	int n;
	cin >> n;

	vector<int> list;
	list.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	vector<int> v(list.size());
	copy(list.begin(), list.end(), v.begin());
	sort(list.begin(), list.end());
	list.resize(n+1);
	v.resize(n + 1);
	int count = 0;
	for (int i = 0; i < n; i++) {//map.insert({ insert, password });
		map.insert({ list[i], count });
	//	cout << list[i] << " c" << count << endl;
		if (list[i] != list[i + 1]) {
			count++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << map[v[i]] << " ";
	}
}
