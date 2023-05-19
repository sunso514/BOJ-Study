#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent(52);
#define FOR(i, N) for(int (i) = 1; (i) <= (N); (i)++)

int N, M;

int Find(int index) {
    if (parent[index] == index) return index;
    return parent[index] = Find(parent[index]);
}
void Union(int x, int y) {
    int x_p = Find(x);
    int y_p = Find(y);
    if (x_p == y_p) return;
    if (x_p == 0 && y_p > 0) parent[y_p] = x_p;
    else if (y_p == 0 && x_p > 0) parent[x_p] = y_p;
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    FOR(i, N) parent[i] = i;

    int li_am; cin >> li_am;
    FOR(i, li_am) {
        int a;  cin >> a;
        parent[a] = 0;
    }

    vector<vector<int>> btr(M + 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int tm; cin >> tm;
        for (int j = 0; j < tm; j++) {
            int b; cin >> b;
            btr[i].push_back(b);
        }
    }
    for(int omg = 0 ; omg < 50; omg++) {
        for(int i = 0; i < M; i++) {
            for (int j = 0; j < btr[i].size() - 1; j++) {
                for (int k = j + 1; k < btr[i].size(); k++) {
                    Union(btr[i][j], btr[i][k]);
                }
            }
        }
    }
    int count = M;
    
    for(int i = 0; i < M; i++) {
        for (int j = 0; j < btr[i].size(); j++) {
            if (parent[btr[i][j]] == 0) {
                count--;
                break;
            }
        }
    }
    cout << count;

}