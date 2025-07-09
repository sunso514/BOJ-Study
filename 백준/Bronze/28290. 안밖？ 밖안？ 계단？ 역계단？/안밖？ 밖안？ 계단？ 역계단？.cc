
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
#define INF 1000000009

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    vector<vector<string>> tabup(4);

    tabup[0].push_back("fdsajkl;");
    tabup[0].push_back("jkl;fdsa");
    tabup[1].push_back("asdf;lkj");
    tabup[1].push_back(";lkjasdf");
    tabup[2].push_back("asdfjkl;");
    tabup[3].push_back(";lkjfdsa");

    string tabup_name[4] = { "in-out", "out-in", "stairs", "reverse" };

    string inp; cin >> inp;
    
    for (int i = 0; i < 4; i++) {
        for (auto j : tabup[i]) {
            if (inp == j) {
                cout << tabup_name[i];
                return 0;
            }
        }
    }
    cout << "molu";
}

