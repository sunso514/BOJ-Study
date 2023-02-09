#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int test; //   
	test = n / 5;
	if (n == 8) {
		cout << 2;
		return 0;
	}
	if (n % 5 == 0) { 
		cout << test;
		return 0;
	}
	if (n / 5 < 3) {
		if (n % 3 == 0) {
			cout << n / 3;
			return 0;
		}
	}
	int store = n - n % 5;
	if (test > 1){
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (store + (j + 1) * 3 == n) {
					cout << test-(i)+(j+1);
					return 0;
				}
			}
		store -= 5;
			
		}
	}
	else {
		cout << -1;
		return 0;
	}
	cout << -1;
	return 0;

}
