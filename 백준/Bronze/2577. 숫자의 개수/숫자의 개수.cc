#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int a, b, c, res;
	cin >> a;
	cin >> b;
	cin >> c;
	res = a * b * c;
	int check[11] = { 0 };
	string str = to_string(res);
	for (int j = 0; j < str.length(); j++) {
		for (int i = 0; i < 10; i++) {
			if (str[j] == i + '0') {
				check[i]++;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << check[i] << endl;
	}
}