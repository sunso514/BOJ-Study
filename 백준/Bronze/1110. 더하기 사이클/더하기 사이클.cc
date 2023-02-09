#include <iostream>
 
using namespace std;
 
int main(int argc, const char *argv[]) {
 
	int it, n;
	int count = 0;
	cin >> it;
 
	n = it;
 
	do {
		n = (n % 10) * 10 + ((n / 10) + (n % 10)) % 10;
		count++; 
	} while (it != n);
 
	cout << count;	// 사이클 수 출력
	return 0;
}