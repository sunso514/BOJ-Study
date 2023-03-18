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

vector<long long> graph;


long long N, M;
long long low = 0, high = 0;

long long checkAm(long long mid) {
    long long pm = 0;
    for (int i = 0; i < N; i++) pm += (mid / graph[i]);
    return pm;
}

void bSearch() {
    long long mid;
    long long HMpeople, res = 0;
    high *= M;

    while (low <= high) {
        mid = (low + high) / 2; // mid : 모두 마치는대에 걸리는 시간
        HMpeople = checkAm(mid); // mid초 안에 몇명이 심사가 가능한가?
        if (HMpeople < M) low = mid + 1;  
        else {
            res = mid;
            high = mid - 1;
        }
    }
    cout << res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        long long a; cin >> a;
        graph.push_back(a);
        low = min(low, graph[i]);
        high = max(low, graph[i]);
    }
    bSearch();
}