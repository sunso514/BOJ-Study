#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string A, B; cin >> A >> B;

    int ans = 0;

    if (A.length() == B.length()) {
        for (int i = 0; i < A.length(); i++) {
            if (A[i] != B[i]) break;
            if (A[i] == B[i] && A[i] == '8') ans++;
        }
    }
    cout << ans;
}