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

int n, m, streak;
string sutja;
//vector<vector<int>> vec;

int getvalue() {
	return stoi(sutja);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string get;
	cin >> get;
	bool minus = false;
	int num = 0;
	for (int i = 0; i < get.length(); i++) {
		if (get[i] == '-') {
		
			if (minus == false) {
				num += getvalue();
				minus = true;
			}
			else num -= getvalue();
			sutja.clear();
		}
		else if (get[i] == '+') {
			if (minus == true) num -= getvalue();
			else num += getvalue();
			sutja.clear();
		}
		else {
			sutja.push_back(get[i]);
			if (i+1 == get.length()) {
				if (minus == false) num += getvalue();
				else num -= getvalue();
			}
		}
	}
	cout << num;
}
