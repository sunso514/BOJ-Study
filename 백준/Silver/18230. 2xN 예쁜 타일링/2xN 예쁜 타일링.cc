#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;

    vector<int> twoxone(A);
    vector<int> twoxtwo(B);
    for (int i = 0; i < A; i++) {
        cin >> twoxone[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> twoxtwo[i];
    }

    sort(twoxone.begin(), twoxone.end());
    sort(twoxtwo.begin(), twoxtwo.end());
    
    long long ans = 0;
    if (N % 2 == 1) {
        ans += twoxone.back();
        twoxone.pop_back();
        N--;
    }
    int tmpA, tmpB;
    for (int i = 0; i < N / 2; i++) {
        tmpA = 0, tmpB = 0;
        if (twoxtwo.size() > 0) tmpA = twoxtwo.back();
        if (twoxone.size() > 1) tmpB = twoxone.back() + twoxone[twoxone.size() - 2];

        if (tmpA > tmpB) {
            twoxtwo.pop_back();
        }
        else {
            twoxone.pop_back();
            twoxone.pop_back();
        }
        ans += max(tmpA, tmpB);
    }
    cout << ans;
}