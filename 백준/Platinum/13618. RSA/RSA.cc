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

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;

vector<int> list;


string inttobin(unsigned int decimal) {
    string binary = bitset<60>(decimal).to_string();
    return binary;
}
void readytomod(string num, int chk) {
    int count = 0;
    while (chk > 0) {
        chk /= 2;
        if (num.back() == '1') list.push_back(pow(2, count));
        num.pop_back();
        count++;
    }
    for (int i = 0; i < list.size(); i++) {
    }
}
long long N, E, C;
long long eu_x; long long eu_y;

long long ex_euclid(long long a, long long b, long long* eu_x, long long* eu_y) {
    if (a == 0) {
        *eu_x = 0; *eu_y = 1;
        return b;
    }
    long long t, s;
    long long gcd = ex_euclid(b % a, a, &t, &s); 
    *eu_x = s - (b / a) * t;
    *eu_y = t;
    return gcd;
}

long long euler_phi(long long x) {
    long long res = 1;
    long long storex = x;
    if (x == 1) return 1;
    for (long long i = 2; i * i <= storex; i++) {
        if (x % i == 0) { // 나누어 떨어진다면
            x /= i;
            long long count = 1;
            while (x % i == 0) { // 나누어 떨어질때까지
                x /= i;
                count++;
            }
            if (count > 1) res *= pow(i, count) - pow(i, count - 1);
            else res *= pow(i, count) - 1;
        }
    }
    if (x > 1) res *= x - 1;
    if (res <= 1) res = storex - 1;
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> E >> C;
    long long e_phi = euler_phi(N); // φ(N) 구하기
    ex_euclid(E, e_phi, &eu_x, &eu_y); // eu_x 구하기 ( DE = 1 ( mod φ(N) ) ) , e*x - phi(N)*y = 1  x = D
    while (eu_x <= 0) eu_x += e_phi; // eu_x가 음수일 때 증가

    string num = inttobin(eu_x);
    readytomod(num, eu_x); // 빠른 거듭제곱 mod 연산 준비

    int now = 0;
    int index = 0;
    vector<long long> mods;
    long long modres = C % N;
    while (1) {
        int check = pow(2, now);
        if (list[index] == check) {
            mods.push_back(modres);
            index++;
        }
        if (check == list.back()) break;
        now++;
        modres *= modres;
        modres = modres % N;
    }
    // A B C D E 가 있으면
    // ( (A * B) mod N ) * C ) mod N . . .
    long long res = mods[0];
    for (int i = 0; i < index - 1; i++) {
        res *= mods[i + 1];
        res = res % N;
    }
    cout << res % N;

}