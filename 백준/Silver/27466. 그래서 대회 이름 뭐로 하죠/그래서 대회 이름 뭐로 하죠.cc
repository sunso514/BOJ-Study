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

//vector<int> list;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    string S, getc;
    cin >> S;

    int a_count = 0;
    while (1) {
        int len = S.length();
        if (len < M) {
            cout << "NO";
            return 0;
        }
        if (S[len-1] == 'A' || S[len - 1] == 'E' || S[len - 1] == 'I' || S[len - 1] == 'O' || S[len - 1] == 'U') {
            S.erase(len - 1);
            continue;
        }
        if (a_count == 2) {
            if (len == M) {
                cout << "YES";
                cout << endl << S;
                return 0;
            }
            S.erase(0, 1);
        }
        else {
            if (S[len - 2 - a_count] == 'A') {
                a_count++;
            }
            else {
                S.erase(len - 2 - a_count, 1);
            }
        }

    }
}