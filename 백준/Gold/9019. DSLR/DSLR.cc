#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <deque>

#define endl "\n"
using namespace std;

int now, goal;
struct JongGang {
    int index, parent;
    char how;
};


vector<int> visit;
vector<JongGang> graph;
queue<JongGang> que;

void bfs() {
    JongGang haja;
    while (!que.empty()) {
        haja = que.front();
        que.pop();
        
        if (haja.index == goal) {
            graph[haja.index].parent = haja.parent;
            graph[haja.index].how = haja.how;
            return;
        }


        else if (visit[haja.index] == true) continue;
        visit[haja.index] = true;
        graph[haja.index].parent = haja.parent;
        graph[haja.index].how = haja.how;
        
        que.push({ (haja.index * 2) % 10000 , haja.index , 'D'});
        que.push({ haja.index == 0 ? 9999 : haja.index-1 , haja.index , 'S'});
        que.push({(haja.index % 1000) * 10 + (haja.index / 1000), haja.index ,'L'});
        que.push({haja.index / 10 + (haja.index % 10) * 1000, haja.index ,'R' });
        
    }
}

/*


*/
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    visit.resize(10001);
    graph.resize(10001, { -1, -1, 'N'});

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        fill(visit.begin(), visit.end(), 0);
        cin >> now >> goal;

        que.push({ now, -5 , 'N'});
        bfs();

        deque<char> jongganghaja;
        int par = goal;
        
        while (true) {
            jongganghaja.push_front(graph[par].how);
            if (graph[par].parent == now) break;
            par = graph[par].parent;
        }
        for (int i = 0; i < jongganghaja.size(); i++) cout << jongganghaja[i];
        cout << endl;
        
        while (!que.empty()) que.pop();
        for (int j = 1; j <= 10001; j++) {
            graph[i].parent = -1;
            graph[i].how = 'N';
        }
    }

}