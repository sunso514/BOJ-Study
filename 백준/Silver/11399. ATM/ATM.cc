#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n = 0;	
	cin >> n;
	int list[1001];
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	sort(list, list+n);
	int res = 0;
	int realres = 0;
	for (int i = 0; i < n; i++) {
		res = list[i]+res;
		realres += res;
	}
	cout << realres;
	
}