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

struct Melon {
    int index; int value;
};


vector<int> graph;
vector<Melon> mem;
vector<int> res;
deque<int> ans;
int N, M;
int low = 0, high = 0;

int bSearch(int goal) {
    int mid = 0;
    low = 0;
    high = res.size() - 1;

    while (low < high) {
        mid = (low + high) / 2;

        //cout  << goal << " " << res[mid] << " " << mid << " / ";
        if (res[mid] < goal) {
            //cout << "low = mid +1 ";
            low = mid + 1;
        }
        else high = mid;
    }
    //cout << "ㅁ " << low << " " << high << endl;
    return high;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    graph.resize(N);
    for (int i = 0; i < N; i++) cin >> graph[i];
    res.push_back(graph[0]);
    mem.push_back({ 0, graph[0] });
    for (int i = 1; i < N; i++) {
        if (res[res.size() - 1] < graph[i]) {
            res.push_back(graph[i]);
            int siz = res.size() - 1;
            mem.push_back({ siz, graph[i] });
        }
        else {
            int index = bSearch(graph[i]);
            res[index] = graph[i];
            mem.push_back({ index, graph[i] });
        }

        for (int i = 0; i < res.size(); i++) {
            //cout << res[i] << " ";
        }
       // cout << endl;
    }

    cout << res.size() << endl;

    return 0; 

    // 플레티넘 5 문제 범위

    int first = res.size();

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << first;
        if (first - 1 == mem[i].index) {
            ans.push_front(mem[i].value);
            first--;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        //cout << ans[i] << " ";
    }

}