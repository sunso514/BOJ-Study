#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>

using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	

	int hour, minute;
	int maketime;
	cin >> hour >> minute >> maketime;
	minute += maketime;
	while (minute >= 60) {
		minute -= 60;
		hour++;
		if (hour >= 24) {
			hour = 0;
		}
	}
	cout << hour << " " << minute;

}