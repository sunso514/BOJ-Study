#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> parentN(201, -1);
int N, M;

int find(int cord) {
    if (parentN[cord] < 0) return cord; // 부모가 없음
    return parentN[cord] = find(parentN[cord]); 
}

void Union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);
    if (x_parent == y_parent) return; // 같은 집합
    if (parentN[x_parent] > parentN[y_parent]) {
        parentN[x_parent] += parentN[y_parent];
        parentN[y_parent] = x_parent;
    }
    else {
        parentN[y_parent] += parentN[x_parent];
        parentN[x_parent] = y_parent;
    }
}


int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int con; cin >> con;
            if (con == true) {
                if (find(i) == find(j)) continue;
                Union(i, j); 
            }
        }
    }

    int start_point;
    cin >> start_point;
    for (int i = 1; i < M; i++) {
        int a; cin >> a;
        if (find(start_point) == find(a)) {
            start_point = a;
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

}