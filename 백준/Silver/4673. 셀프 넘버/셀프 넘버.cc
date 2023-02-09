#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int check[10000] = { 0 };
	for (int j = 0; j < 10000; j++) {
		if (check[j] != -1) {
			int res = j + 1;
			while (res <= 10000) {
				string test = to_string(res);
				for (int i = 0; i < test.length(); i++) {
					res += (test[i] - '0');	
				}
				if (res <= 10000) {
					check[res - 1] = -1;
				}
			}
		}
	}
	for (int i = 1; i < 10000; i++) {
		if (check[i-1] != -1) cout << i << "\n";
	}

}