#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;




int main() {
	int n = 0, k;
	cin >> n >> k;
	int list[1000];
	for (int i = 0; i < n; i++) {
		list[i] = i + 1;
	}
	int count = n;
	int plus = 0;
	for (int i = 0; i < n; i++) {
		int omg = k;
		for (int j = 0; j < omg-1; j++) {
			int firstnum = list[plus]; // 옆으로 밀기
			for (int p = 0; p < count-1; p++) {
				list[plus+p] = list[plus+p + 1];
			}
			list[n - 1] = firstnum;
			for (int np = 0; np < count; np++) {
			}
		}
		count--;
		plus++;
		for (int np = 0; np < count; np++) {
		}
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		cout << list[i];
		if (i != n - 1) cout << ", ";
	}
	cout << ">";
}