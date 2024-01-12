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

    vector<int> attack;
    vector<int> avoid;
    vector<int> adnel;

    cin >> N;

    
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        attack.push_back(value);
    }
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        avoid.push_back(value);
    }
    for (int i = 0; i < N; i++) {
        double value;
        cin >> value;
        value *= 10;
        adnel.push_back(value);
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += max(attack[i] * adnel[i]/10 - avoid[i], attack[i] - avoid[i] * adnel[i]/10);
    }
    cout << sum;

}