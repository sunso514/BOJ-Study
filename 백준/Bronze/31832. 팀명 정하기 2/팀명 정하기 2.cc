#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

pair<int, int> get_letters(string N) {
	int small = 0;
	int big = 0;
	for (auto i : N) {
		if (i >= 'a' && i <= 'z') small++;
		if (i >= 'A' && i <= 'Z') big++;
	}
	return { small, big };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	while (N--) {
		string get;
		cin >> get;
		pair<int, int> l_count = get_letters(get);
		if (l_count.first < l_count.second) continue;
		if (get.length() > 10) continue;
		if (l_count.first == 0 && l_count.second == 0 && get.find('-') == string::npos) continue;

		cout << get;
		break;
	}
}