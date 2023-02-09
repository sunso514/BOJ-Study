#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>


using namespace std;

int main() {
	int a;
	cin >> a;
	for (int j = 0; j <= 1000000; j++) {
		int res = j + 1;
		string test = to_string(res);
		for (int i = 0; i < test.length(); i++) {
			res += (test[i] - '0');
		}
		if (res == a) {
			cout << j + 1;
			return 0;
		}
		if (j >= a) {
			cout << "0";
			return 0;
		}

	}
	
}