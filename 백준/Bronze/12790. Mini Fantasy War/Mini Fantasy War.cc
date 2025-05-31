#include <bits/stdc++.h>
using namespace std;
int main()
{	
	int N; cin >> N;
	int a, aa, b, bb, c, cc, d, dd;
	while (N--) {
		cin >> a >> b >> c >> d;
		cin >> aa >> bb >> cc >> dd;
		a += aa, b += bb, c += cc, d += dd;
		cout << max(1, a) + 5 * max(1, b) + 2 * max(0, c) + 2 * d << '\n';
	}

	return 0;
}