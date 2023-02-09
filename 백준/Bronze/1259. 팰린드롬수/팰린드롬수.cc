#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main() {
	while (true) {
		string str;
		cin >> str;
		string strr;
		strr = str;
		if (str[0] - '0' == 0) return 0;
		reverse(strr.begin(), strr.end());
		int num;
		int nn = 0;
		num = str.length();
		for (int i = 0; i < num; i++) {
			if (strr[i] == str[i]) {
				nn++;
			}
		}
		if (nn == num) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}