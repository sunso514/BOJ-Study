#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
using namespace std;

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;

int times;
vector<int> nodes(1500, 0);
vector<int> res[100];


void treeinorder(int depth, int st, int end) {
    int mid = (st + end) / 2;

    if (depth >= times) return;
    if (mid < 0) return;
    
    if (st == end) {
        res[depth].push_back(nodes[st]);
        return;
    }
    res[depth].push_back(nodes[mid]);
    treeinorder(depth + 1, st, mid-1); // start의 mid의 중간
    treeinorder(depth + 1, mid + 1, end); // mid+1와 end의 중간점
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> times;
    int inputnum = pow(2, times) - 1;
    for (int i = 0; i < inputnum; i++) cin >> nodes[i];

    treeinorder(0, 0, inputnum-1);
    for (int i = 0; i < times; i++) {
        for (auto j : res[i]) cout << j << ' ';
        cout << endl;
    }
}