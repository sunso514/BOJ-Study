
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

int N; 

int main(void) {
    cin.tie(NULL);

    double cost[3];
    double weight[3];
    string snu = "SNU";

    for (int i = 0; i < 3; i++) {
        cin >> cost[i] >> weight[i];
        cost[i] *= 10;
        weight[i] *= 10;
        
        if (cost[i] >= 5000) cost[i] -= 500;
    }

    double maxV = -1;
    char ans = '-';
    for (int i = 0; i < 3; i++) {
        double gasungbee = weight[i] / cost[i];
        if (maxV < gasungbee) {
            ans = snu[i];
            maxV = gasungbee;
        }
    }
    cout << ans;
}