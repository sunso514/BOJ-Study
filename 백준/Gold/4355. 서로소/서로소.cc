#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#define test "Test "

using namespace std;

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;

long long N;
long long euler_phi(long long x){
    long long res = 1;
    long long storex = x;
    for (long long i = 2; i * i <= storex; i++) {
        if (x % i == 0) { // 나누어 떨어진다면
            x /= i;
            int count = 1;
            while (x % i == 0) { // 나누어 떨어질때까지 ( 소인수 구하기 )
                x /= i;
                count++;
            }
            if (count > 1) res *= pow(i, count) - pow(i, count - 1);
            else res *= pow(i, count) - 1;
            
        }
    }
    if (x > 1) {
        res *= x - 1;
    }
    if (res <= 1) {
        res = storex-1;
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true) {
        cin >> N;
        if (N == 0) break;
        cout << euler_phi(N) << "\n";
    }


}