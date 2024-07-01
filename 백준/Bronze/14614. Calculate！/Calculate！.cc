#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned int A;
	unsigned int B;
	string C;
	cin >> A >> B >> C;	
	int N = (C.back() - '0') % 2;

	for (int i = 0; i < N; i++) {
		A ^= B;
	}
	cout << A;
}