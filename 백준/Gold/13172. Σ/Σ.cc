#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <numeric>
#include <bitset>
#define test "Test "

using namespace std;

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999
long long MOD = 1'000'000'007;
//vector<int> list;



long long ex_euclid(long long a, long long b, long long* x, long long* y) {
    if (a == 0) {
        *x = 0; *y = 1;
        return b;
    }
    long long e_x, e_y;
    long long gcd = ex_euclid(b % a, a, &e_x, &e_y);
    *x = e_x - (b / a) * e_y;
    *y = e_y;
    return gcd;

}

long long mz(long long x, long long y) {
    if (y == 1) return x;
    if (y% 2 == 1) return x * mz(x, y - 1) % MOD;
    long long t = mz(x, y / 2);
    return t * t  % MOD;
}



int main() {


    long long a,b, N;
    cin >> N;

    long long answer = 0;

    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        long long x, y;
        long long gcd = ex_euclid(a, b, &x, &y);
        a /= gcd; 
        b /= gcd;
        answer += b * mz(a, MOD - 2) % MOD;

        answer %= MOD;
        
    }
    cout << answer;

}