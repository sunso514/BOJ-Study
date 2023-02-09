#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a; j++) {
			cout << "*";
		}
		cout << endl;
		a--;
	}

}