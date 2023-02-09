
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
struct banana{
    int value;
    int index;
};

struct cmp {
    bool operator()(banana a, banana b) {
        return a.value > b.value;
    }
};

vector<vector<int>> graph;
int N, M;
int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    
    priority_queue <banana, vector<banana>, cmp> pq;

    int get;
    for (int i = 0; i < N; i++) {
        cin >> get;
        pq.push({ get, i });
        while(true) {
            banana p = pq.top();
            if (i - M + 1 <= p.index && p.index <= i) {
                cout << p.value;
                if (p.index != N - 1) {
                    cout << " ";
                }
                break;
            }
            else pq.pop();       
        }
    }
}