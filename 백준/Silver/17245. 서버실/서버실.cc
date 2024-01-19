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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    deque<int> vec;
    set<int> st;
    map<int, int> mp;

    int a;
    long long total = 0;
    long long size = 0;
    FOR(i, N) FOR(j, N) {
        cin >> a;
        total += a;
        if (a != 0) {
            st.insert(a);
            //if (mp.find(a) == mp.e 
            mp[a] += 1;
            size += 1;
        }
    }
    
    for (set<int>::iterator itr = st.begin(); itr != st.end(); ++itr) {
        vec.push_back(*itr);
    }
    long long mid = total / 2;
    long long mid_mod = total % 2;
    
    long long ans = 0;

    if (vec.size() == 0) {
        cout << 0;
        return 0;
    }

    FOR(i, vec.back()) {
        ans += size;
        if (vec.front() == i + 1) {
            size -= mp[i + 1];
            vec.pop_front();
        }
        if (ans >= mid + mid_mod) {
            cout << i + 1;
            return 0;
        }
        if (vec.empty()) {
            cout << i + 1;
            return 0;
        }
    }
}