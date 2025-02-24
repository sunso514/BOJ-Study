#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <deque>

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

struct Truck {
    int loc, weight;
};


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, W, L;
    cin >> N >> W >> L;
    queue<int> trucks;
    FOR(i, N) {
        int a; cin >> a; trucks.push(a);
    }

    deque<Truck> bridge;

    int time = 0;
    int total_w = 0;
    while (true) {
        
        if (bridge.empty() && trucks.empty()) break;
        time++;

        // 모든 트럭들을 1씩 앞으로 옮긴다.
        for (int i = 0; i < bridge.size(); i++) {
            bridge[i].loc++;
        }

        // 다리를 건넌 트럭 제거
        if ((!bridge.empty()) && (bridge.front().loc > W)) {
            total_w -= bridge.front().weight;
            bridge.pop_front();
        }

        // 새로운 트럭을 옮길 수 있다면 옮긴다.
        if (trucks.empty()) continue;
        if (trucks.front() + total_w > L) continue;
        bridge.push_back({ 1, trucks.front() });
        total_w += trucks.front();
        trucks.pop();
    }

    cout << time;

}
    