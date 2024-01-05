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

#define test "test "
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

long long powV(long long a, long long b) {
    long long res = 1;
    
    for (int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N;
    cin >> N;
    string iToBit = bitset<42>(N).to_string();
    //cout << iToBit;
    long long res = 0;

    int now;
    for (int i = 0; i < 42; i++) {
        now = iToBit.length()-i-1;
        //cout << iToBit[now];
        if (iToBit[now] == '1') {

            res += powV(3, i);
        }
    }
    //cout << endl;
    cout << res;
}