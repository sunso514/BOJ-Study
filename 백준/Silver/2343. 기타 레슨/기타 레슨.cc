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

vector<int> graph;


int N, M;
int low = 0, high = 0;

int bAmount(int mid) {
    int vlen = 0, bcount = 0;
    for (int i = 0; i < N; i++) {
        if (vlen + graph[i] > mid) { // 블루레이 길이 초과
            vlen = 0; bcount++;
        }
        vlen += graph[i];
    }
    return bcount + 1;
}

void bSearch() {
    int minBsiz = 0;
    int mid, howmany;
    while (low <= high) {
        mid = (low + high) / 2;
        howmany = bAmount(mid);

        if (howmany > M) { // 블루레이 크기가 작아서 더 많이 필요함 그럼 low를 mid로
            low = mid +1;
        }
        else {
            minBsiz = mid;
            high = mid - 1;
        }
    }
    cout << minBsiz;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        graph.push_back(a);
        low = max(low, graph[i]); // 가장 긴 블루레이 길이 ( 가장 긴 것보다 작으면 담을 수가 없다. )
        high += graph[i];
    }
    bSearch();
}