#include <iostream>
#include <algorithm>
#include <deque>
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;  
    deque<int> minus;
    deque<int> plus;
    
    FOR(i, N) {
        int a; cin >> a;
        (a < 0) ? minus.push_back(a) : plus.push_back(a);
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());

    int ans = 0;

    if ((N <= M) && (minus.size() <= 0 || plus.size() <= 0)) {
        (minus.size() > 0) ? ans += abs(minus.front()) : ans += plus.back();
        cout << ans;
        return 0;
    }

    if (plus.size() == 0) plus.push_front(0);
    if (minus.size() == 0) minus.push_front(0);

    // 젤 큰놈 부터 처리 ( 왕복 X )
    if (plus.back() > abs(minus.front())) {
        ans += plus.back();
        FOR(i, M) if (plus.size() > 0) plus.pop_back();
    }
    else {
        ans += abs(minus.front());
        FOR(i, M) if (minus.size() > 0) minus.pop_front();
    }

    // 나머지 덩이 처리
    while (!plus.empty()) {
        ans += plus.back() * 2;
        FOR(i, M) if (plus.size() > 0) plus.pop_back();
    }
    while (!minus.empty()) {
        ans += abs(minus.front()) * 2;
        FOR(i, M) if (minus.size() > 0) minus.pop_front();
    }
    
    cout << ans;
    
}