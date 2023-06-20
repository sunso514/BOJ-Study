#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

vector<int> parent(300002, -1);

int find(int cord) {
    if (parent[cord] < 0) return cord;
    return parent[cord] = find(parent[cord]);
}

void Union(int x, int y) {
    int x_p = find(x);
    int y_p = find(y);

    if (x_p == y_p) return;
    parent[y_p] = x_p;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;

    for (int i = 0; i < N-2; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    for (int i = 2; i <= N; i++) {
        if (find(1) != find(i)) {
            cout << 1 << " " << i;
            return 0;
        }
    }
}