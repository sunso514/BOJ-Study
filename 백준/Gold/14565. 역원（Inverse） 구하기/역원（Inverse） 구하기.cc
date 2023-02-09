
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <bitset>
#define test "Test "
using namespace std;

long long ex_euclid(long long a, long long b, long long* eu_x, long long* eu_y) {
    if (a == 0) {
        *eu_x = 0; *eu_y = 1;
        return b;
    }
    long long t, s;
    long long gcd = ex_euclid(b % a, a, &t, &s); // 유클리드 호제법
    *eu_x = s - (b / a) * t;
    *eu_y = t;
    return gcd;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    long long a, N;
    cin >> N >> a;
    cout << N-a << " ";

    long long eu_x, eu_y;
    long long gcd = ex_euclid(a, N, &eu_x, &eu_y);
    while (eu_x < 0) eu_x += N;
    if (gcd != 1) cout << -1;
    else cout << eu_x;
}