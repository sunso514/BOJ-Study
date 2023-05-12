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
#include <ranges>
#define test "test "
#define endl "\n"
using namespace std;

vector<int> parent;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define debug for (int j = 0; j < G; j++) cout << parent[j] << " "; cout << endl;
struct JongGang {
    int index, depth;
};

int G, P;


int find(int cord) {
    if (cord == -1) return -1;
    if (parent[cord] == -2) return cord; // 빈자리
    return parent[cord] = find(parent[cord]);
}


void Union(int x, int y) {
    int x_p = find(x);
    int y_p = find(y);
    parent[x_p] = y_p;
}



int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);
 
    cin >> G;
    parent.resize(G + 1, -2);

    cin >> P;
    int count = 0;
    for (int i = 0; i < P; i++) {
        int a; cin >> a; a--;
        if (parent[a] == -2) { // 빈 자리면 착석
            parent[a] = a - 1;
            count++;
            continue;
        }
        int p = find(a); // 빈자리가 아니면 어디가 비었는지 한 번 본다.
        if (p == -1) {
            break;
        }
        else {
            Union(p, p - 1);
            count++;
        } 
    }
    cout << count;
   
}