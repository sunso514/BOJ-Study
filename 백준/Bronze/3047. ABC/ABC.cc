#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N[3];
	cin >> N[0] >> N[1] >> N[2];
	sort(N, N + 3);
	for (int i = 0; i < 3; i++) {
		char tmp; cin >> tmp;
		cout << N[tmp - 'A'] << ' ';
	}
}