#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#define test "test "
#define endl "\n"


using namespace std;

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;

int ex_euclid(int a, int b, int* x, int* y) {
    if (a == 0) {
        *x = 0; *y = 1;
        return b;
    }
    int tmf, tmc;
    int gcd = ex_euclid(b % a, a, &tmf, &tmc);
    *x = tmc - (b / a) * tmf;
    *y = tmf;

    return gcd;
}


int N;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int K, C;
        cin >> K >> C;

        // x : 사람마다 필요한 사탕 개수 y : 봉다리 개수 
        int x, y;
        if (ex_euclid(K, C, &x, &y) != 1) {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }
        //kx + 1 = cy 이므로 cy - kx = 1
        while (y <= 0) y += K; // 음수 양수처리
        if (C == 1) {

            y = K + 1;
        }
        if (y > 1000000000) {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }
        cout << y << "\n";
    }
    


}