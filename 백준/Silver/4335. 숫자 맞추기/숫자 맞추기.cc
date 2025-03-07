#include <iostream>
#include <string>

using namespace std;
int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    int mn = -1; int mx =  11;

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        string a, cmd;
        cin >> a >> cmd;
        if (cmd == "high") mx = min(mx, N);
        else if (cmd == "low") mn = max(mn, N);
        else {
            // 결과 보기
            if (mx <= mn) cout << "Stan is dishonest\n";
            else if (N == mx || N == mn || N < mn || N > mx) cout << "Stan is dishonest\n";
            else cout << "Stan may be honest\n";
            mn = -1;
            mx = 11;
        }
    }
}
