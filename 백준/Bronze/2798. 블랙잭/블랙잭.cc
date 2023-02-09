#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>


using namespace std;

int cd[101];

int check(int n, int m) {
	int sb = 100000;
	int sm = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (sb > m - (cd[i] + cd[j] + cd[k]) && m - (cd[i] + cd[j] + cd[k]) >= 0){
					sb = m - (cd[i] + cd[j] + cd[k]);
					sm = cd[i] + cd[j] + cd[k];
				}
			}
		}
	}
	return sm;
}


int main() {
	int n, m;
	int cdn;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cdn;
		cd[i] = cdn;
	}
	cout << check(n, m);
	
}