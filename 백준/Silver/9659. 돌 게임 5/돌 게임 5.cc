#include <iostream>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long a;
	cin >> a;

	if (a % 2 == 0) cout << "CY";
	else cout << "SK";
}