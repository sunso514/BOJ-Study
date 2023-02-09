#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;


int factorial(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << factorial(n) / (factorial(k) * factorial(n - k)) << endl;

}