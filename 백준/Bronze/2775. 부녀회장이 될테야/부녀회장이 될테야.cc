#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> home;


int getDownstair(int floor, int ho);

int getDownstair(int floor, int ho) {
	int res = 0;
	if (floor == 0) {
		return ho+1;
	}
	for (int i = 0; i <= ho; i++) {
		res += home[floor-1][i];
	}
	return res;
}
int main() {
	int time;
	cin >> time;
	for (int t = 0; t < time; t++) {
		int floor, ho;
		cin >> floor >> ho;
		home.resize(15, vector<int>(15));
		for (int j = 0; j <= floor; j++) {
			for (int k = 0; k < ho; k++) {
				home[j][k] = getDownstair(j, k);
				//cout <<j << "층" <<k << "호 명 : " << home[j][k] << endl;
				if (floor == j && ho-1 == k) {
					cout << home[j][k] << endl;
				}
			}
		}
	}
}