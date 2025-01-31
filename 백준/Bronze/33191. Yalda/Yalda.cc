
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

struct Item {
    int value, index;
};


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int money; cin >> money;
    int a, b, c;
    cin >> a >> b >> c;
    if (money >= a) cout << "Watermelon";
    else if (money >= b) cout << "Pomegranates";
    else if (money >= c) cout << "Nuts";
    else cout << "Nothing";

}
    