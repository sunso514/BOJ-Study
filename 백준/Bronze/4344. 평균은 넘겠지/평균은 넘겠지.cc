#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {

	int time;
	cin >> time;
	for (int p = 0; p < time; p++) {
		int n;
		cin >> n;
		double list[1001] = { 0.00000001 };
		double res = 0, completed = 0;
		for (int i = 0; i < n; i++) {
			cin >> list[i];
			res = list[i] + res;
		}
		res = res / n;
		for (int i = 0; i < n; i++) {
			if (res < list[i]) {
				completed++;
			}
		}
		double result = (double)completed * 100 / (double)n;
		cout << fixed;
		cout.precision(3);
		cout << result << "%\n";
	}
}