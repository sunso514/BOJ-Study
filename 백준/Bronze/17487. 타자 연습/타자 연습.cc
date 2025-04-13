
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



bool isThisRight(char a) {
    string right = "uiophjklnm";
    for (auto c : right) {
        if (c == a) return true;
    }
    return false;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    //string left = "qwertyasdfgzxcvb";
    
    string N;
    getline(cin, N);
    
    int bonus = 0;
    int left = 0;
    int right = 0;
    for (auto c : N) {
        if (c == ' ') {
            bonus++;
            continue;
        }
        if (c < 97) {
            c += 32;
            bonus++;
        }
        (isThisRight(c) == true) ? (right++) : (left++);
    }
    while (bonus > 0) {
        if (left > right) right++;
        else left++;
        bonus--;
    }
    cout << left << " " << right;

}
