
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
#include <iomanip>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;



int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	
    double K, P, X;
    cin >> K >> P >> X;

    double min_c = 1000000000009;
    for (int m = 1; m <= 1000000; m++) {
        double cost = X * m + (P * K) / m;
        if (cost < min_c) {
            min_c = cost;
        }
    }

    cout << fixed << setprecision(3) << min_c << endl;
}
