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

vector<int> parent;


int find(int nod){
    if (parent[nod] == nod) return nod; // 루트 정점
    return parent[nod] = find(parent[nod]);
}

bool Union(int x, int y){
    int tx = find(x);
    int ty = find(y);
    if (tx == ty) return false; // 같은 사이클
    if (tx > ty) parent[tx] = ty;
    else parent[ty] = tx;

    return true;
}




int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    parent.assign(N, 0);
    for(int i = 0; i < N; i++){
        parent[i] = i; // 자기 자신을 부모로 설정
    }
    for(int i = 0; i < M; i++){
        int a,b; cin >> a >> b;
        if (!Union(a, b)) { // 사이클 생성이 되었다면?
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
}