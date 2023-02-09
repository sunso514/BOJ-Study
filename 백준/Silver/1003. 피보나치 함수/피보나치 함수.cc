#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>

using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int tm;
	int n;
	int fb[42][2];
	fb[0][1] = 0;
	fb[1][0] = 0;
	fb[0][0] = 1;
	fb[1][1] = 1;
	for (int i = 2; i < 42; i++) {
		fb[i][0] = fb[i - 1][0] + fb[i - 2][0];
		fb[i][1] = fb[i - 1][1] + fb[i - 2][1];
	}
	cin >> tm;
	for (int i = 0; i < tm; i++) {
		cin >> n;
		cout << fb[n][0] << " " << fb[n][1] << "\n";
	}



}