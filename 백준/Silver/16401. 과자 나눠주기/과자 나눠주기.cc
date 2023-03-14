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

struct Location {
    int x, depth;
};

queue<Location> que;
vector<int> lists;
vector<int> visit;

int M, N;


int searchHMany(int len) {
    long long s = 0;
    for (int i = 0; i < N; i++) s += lists[i] / len;
    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> M >> N;
    int a, high = 0;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a > high) high = a;
        lists.push_back(a);
    }
    int low = 1;
    while (low < high) {
        int mid = (high + low + 1) / 2;
        if (searchHMany(mid) >= M) low = mid;
        else high = mid - 1;
    }

    int length = (high + low) / 2;
    if (searchHMany(length) >= M) cout << length;
    else cout << 0;


}