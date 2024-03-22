#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N = 0;
	cin >> N;
	N = 1000 - N;
    
	int count = 0;
	int a[6] = { 500, 100, 50, 10, 5, 1 };
	
	for (int i = 0; i < 6; i++) {
		while (N >= a[i]) {
			N -= a[i];
			count++;
		}
	}
	cout << count;
	
}