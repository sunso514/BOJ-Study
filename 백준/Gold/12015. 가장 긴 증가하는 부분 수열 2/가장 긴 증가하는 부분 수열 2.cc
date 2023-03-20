#include <iostream>
#include <vector>
#include <deque>
#define endl "\n"

using namespace std;

vector<int> graph;
vector<int> res;
int N, M;
int low = 0, high = 0;

int bSearch(int goal) {
    int mid = 0;
    low = 0;
    high = res.size() - 1;

    while (low < high) {
        mid = (low + high) / 2;
        if (res[mid] < goal) {
            low = mid + 1;
        }
        else high = mid;
    }
    return high;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    graph.resize(N);
    for (int i = 0; i < N; i++) cin >> graph[i];
    res.push_back(graph[0]);
    for (int i = 1; i < N; i++) {
        if (res[res.size() - 1] < graph[i]) {
            res.push_back(graph[i]);
            int siz = res.size() - 1;
        }
        else {
            int index = bSearch(graph[i]);
            res[index] = graph[i];
        }
    }

    cout << res.size() << endl;

    return 0; 

}