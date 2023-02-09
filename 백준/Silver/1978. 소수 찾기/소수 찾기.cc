#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;




int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n = 1000;
	int gaesu;
	cin >> gaesu;
	vector<bool> vec(n + 1);
	vec[1] = true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (vec[i]) continue;
		for (int j = i + i; j <= n; j += i) vec[j] = true;
	}
	int count = 0;
	for (int i = 0; i < gaesu; i++) {
		int a;
		cin >> a;
		if (!vec[a]) count++;
	}
	cout << count;
	/*
	for (int i = 2; i <= n; i++) {
		if (!vec[i]) cout << i << "\n";
	}
	*/


	
}