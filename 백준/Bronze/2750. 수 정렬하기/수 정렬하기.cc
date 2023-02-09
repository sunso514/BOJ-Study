#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int time;
	cin >> time;
	vector<int> vec(time);
	for (int i = 0; i < time; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < time; i++) {
		cout << vec[i] << endl;
	}
}