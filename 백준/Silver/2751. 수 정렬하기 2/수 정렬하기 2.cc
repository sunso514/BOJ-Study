#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int time;
	cin >> time;
	vector<int> vec(time);
	for (int i = 0; i < time; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < time; i++) {
		cout << vec[i] << "\n";
	}
}