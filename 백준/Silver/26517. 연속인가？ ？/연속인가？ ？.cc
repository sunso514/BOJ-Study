#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
//	vector<int> list(time);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long k;
	cin >> k;
	long long a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a * k + b == c * k + d) cout << "Yes " << a * k + b;
	else cout << "No";


}