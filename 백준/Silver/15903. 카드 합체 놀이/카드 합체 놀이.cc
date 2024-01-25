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
#include <set>
#include <tuple>

#include <bitset>

#define test "test "
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

struct compare {
    bool operator()(long long n1, long long n2) {
        if (n1 > n2) return true;
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    priority_queue<long long, vector<long long>, compare> pq;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        long long a; cin >> a;
        pq.push(a);
    }

    for (int i = 0; i < M; i++) {
        long long a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }
    
    long long ans = 0;
    for(int i = 0; i < N; i++){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}