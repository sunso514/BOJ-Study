#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int day, math, korean, pmath, pkorean;
	cin >> day;
	cin >> math;
	cin >> korean;
	cin >> pmath;
	cin >> pkorean;

	int res1 = math / pmath;
	int res2 = korean / pkorean;

	if (res1 > res2) {
		if ((math % pmath) != 0) {
			res1++;
		}
		res1 = day - res1;
		cout << res1;
	}
	else {
		if ((korean % pkorean) != 0) {
			res2++;
		}
		res2 = day - res2;
		cout << res2;
	}





}