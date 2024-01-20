#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, W;
    cin >> N >> W;

    if (N == 1) {
        cout << W;
        return 0;
    }

    vector<long long> price(N);
    for (int i = 0; i < N; i++) cin >> price[i];


    vector<long long> inflection_point;
    // -1 : 하락, 0 : X , 1: 상승
    int info = 0;
    inflection_point.push_back(price[0]);
    for (int i = 1; i < N; i++) {
        //상승
        if (price[i] > price[i - 1]) {
            if (info == -1) inflection_point.push_back(price[i - 1]);
            info = 1;
        }
        //하락
        else if (price[i] < price[i - 1]) {
            if (info == 1) inflection_point.push_back(price[i - 1]);
            info = -1;
        }

        if (i == N - 1 && info == 1) inflection_point.push_back(price[i]);
    }

    
    long long amount = 0;
    for (int i = 0; i < inflection_point.size()-1; i++) {
        if (inflection_point[i] < inflection_point[i + 1] && W >= inflection_point[i]) {
            amount += W / inflection_point[i];
            W -= inflection_point[i] * amount;
        }
        else {
            W += inflection_point[i] * amount;
            amount = 0;
        }
    }
    W += inflection_point[inflection_point.size() - 1] * amount;
    cout << W;
}