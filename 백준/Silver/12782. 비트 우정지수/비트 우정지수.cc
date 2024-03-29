#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    for (int tc = 0; tc < N; tc++) {
        string a, b;
        cin >> a >> b;

        int ans = a.length();
        int tmp[2] = { 0, 0 };
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == b[i]) ans--;
            else tmp[a[i] - '0']++;
        }
        ans -= min(tmp[0], tmp[1]);
        cout << ans << endl;
    }
}