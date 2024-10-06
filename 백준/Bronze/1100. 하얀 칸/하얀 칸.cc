#include<iostream>
using namespace std;
int main(void) {
	int ans = 0;
	char p[100][100];
	for (int i = 0; i < 8; i++)
		cin >> p[i];
	for (int i = 0; i < 8; i++) {
		for (int j = i % 2; j < 8; j += 2) {
			if (p[i][j] == 'F')
				ans++;
		}
	}
	cout << ans << endl;
}