#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)
using namespace std;

struct Oven {
    int now;
    int addh, addt, mint, addo, mino, count;
};

vector<Oven> oven(81);
vector<Oven> oventwo(81);
queue<Oven> que;



void bfs(bool type) {
    Oven tmp;

    vector<bool> visit(81);

    while (!que.empty()) {
        tmp = que.front();
        que.pop();
        if ((tmp.now >= 0 && tmp.now <= 60) && visit[tmp.now] == false) {
            visit[tmp.now] = true;
            if (type == false) oven[tmp.now] = tmp;
            else oventwo[tmp.now] = tmp;
            que.push({ tmp.now + 10, tmp.addh, tmp.addt + 1, tmp.mint, tmp.addo, tmp.mino, tmp.count+1 });
            que.push({ tmp.now - 10, tmp.addh, tmp.addt, tmp.mint + 1, tmp.addo, tmp.mino, tmp.count+1 });
            que.push({ tmp.now + 1, tmp.addh, tmp.addt, tmp.mint, tmp.addo + 1, tmp.mino, tmp.count+1 });
            que.push({ tmp.now - 1, tmp.addh, tmp.addt, tmp.mint, tmp.addo, tmp.mino + 1, tmp.count+1 });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    que.push({ 0, 0, 0, 0, 0, 0 });
    bfs(false);
    que.push({ 60, 0, 0, 0, 0, 0 });
    bfs(true);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        int v = N % 60;
        
        if (oven[v].count > oventwo[v].count + 1 ) {
            cout << (N / 60) + 1 << " " << oventwo[v].addt << " " << oventwo[v].mint << " " << oventwo[v].addo << " " << oventwo[v].mino << endl;
        }
        else {
            cout << (N / 60) << " " << oven[v].addt << " " << oven[v].mint << " " << oven[v].addo << " " << oven[v].mino << endl;
        } 
    }
}