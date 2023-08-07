#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    map<string, int> mp;
    map<int, string> mpt;

    int loc = -1;

    FOR(i, N) {
        string word; cin >> word;

        if (word == "?") loc = i;
        else {
            mp[word] = i;
            mpt[i] = word;
        }
    }
    int hb; cin >> hb;
    FOR(i, hb) {
        string a; cin >> a;
        if (mp.find(a) != mp.end()) continue;

        if (loc > 0) {
            //cout << mpt[loc - 1] << " ";
            if (a[0] != mpt[loc - 1][mpt[loc - 1].length() - 1]) continue;
        }
        if (loc < N - 1) {
            //cout << mpt[loc + 1] << " ";
            if (a[a.length() - 1] != mpt[loc + 1][0]) continue;
        }
        cout << a;
    }
}