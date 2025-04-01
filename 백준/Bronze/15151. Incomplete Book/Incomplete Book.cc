
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <deque>
#include <set>
#include <tuple>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;



int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	
	long long k, d;
	cin >> k >> d;
	
	int time = k;
	int now_time = k;
	int ans = 1;
	while (true) {

		time *= 2;
		
		if (now_time + time> d) {
			break;
		}
		now_time += time;
		ans++;
	}
	cout << ans;
	return 0;
}
