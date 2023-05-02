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
#define test "test "
#define endl "\n"
using namespace std;

#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)


vector<int> num(2001);
vector<vector<int>> available(2001, vector<int>(2001, -1));

int checkpalindrop(int x, int y, int A) {
    if (x > y) return 1;    
    if (A == -1) {
        int tmp;
        if (num[x] == num[y]) {
            tmp = checkpalindrop(x + 1, y - 1, available[x + 1][y - 1]);
        }
        else tmp = 0;
        available[x][y] = tmp;
        return tmp;
    }
    else {
        return A;
    }
}


int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> num[i];

    for (int i = 0; i < N; i++) {
        available[i][i] = 1; // i 부터 i 까지는 무조건 true
        if (num[i] == num[i + 1]) available[i][i + 1] = 1; // 범위가 2인 경우, 앞 뒤 같으면 ok 
    }



    int times; cin >> times;
    for (int i = 0; i < times; i++) {
        int a, b; cin >> a >> b;
        cout << checkpalindrop(a-1, b-1, available[a-1][b-1]) << endl; 
    }


}