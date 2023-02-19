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
using namespace std;
const int INF = 999999999;
int N, M;

vector<int> parentN;


int find(int cord) {
    if (parentN[cord] < 0) return cord;
    return parentN[cord] = find(parentN[cord]); // 그래프 압축하여 루트 정점 찾기
}

void unionInp(int x, int y) {
    int xp = find(x);
    int yp = find(y);

    if (xp == yp) return;// 같은 집합
    if (parentN[xp] < parentN[yp]) { // 새로운 루트 xp
        parentN[xp] += parentN[yp];
        parentN[yp] = xp;
    } 
    else {
        parentN[yp] += parentN[xp];
        parentN[xp] = yp;
    }

}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    parentN.assign(N+1, -1);
    int command, a, b;
    for (int i = 0; i < M; i++) {
        cin >> command >> a >> b;

        if (command == 0) unionInp(a, b);
        else if (command == 1) {
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}