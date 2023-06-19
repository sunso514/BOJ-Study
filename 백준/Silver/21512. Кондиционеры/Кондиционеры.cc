#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N, M;


struct AirInfo {
    int watt, price;
};

bool compare(AirInfo & p1, AirInfo & p2) {
    if (p1.price == p2.price) {
        return p1.watt < p2.watt;
    }
    else return p1.price < p2.price;

}
vector<int> needWatt;
vector<AirInfo> aircon;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int inp; cin >> inp;
        needWatt.push_back(inp);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        aircon.push_back({ a, b });
    }
    // 최적의 경우의 수만 남겨놓는다.

    sort(aircon.begin(), aircon.end(), compare);

    int res = 0;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < aircon.size(); j++) {
            if (needWatt[i] <= aircon[j].watt) {
                res += aircon[j].price;
                break;
            }
        }
    }
    cout << res;
}