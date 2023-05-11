#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)
struct JongGang {
    int index, depth;
};

int T, ans;

int pick[100001];
vector<bool> visit(1000002);

JongGang dfs(int index, int depth) {
    if (visit[index]) return { index, depth };
    visit[index] = true;
    JongGang Haja;
    Haja = dfs(pick[index], depth + 1); // 2 3 4 5 2  연결되어있을 경우 3, 4, 5, 하다가 2에서 visit이 있어서 막힘 반환 값 { 2, 5 }
    if (Haja.index == index) {
        ans -= Haja.depth - depth; // 최종 1 2 3 4 2 일 경우 최종 depth 5 에서 현재 dpeth 2를 빼주면 3이 된다.
    }
    return Haja;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    cin >> T; 
    FOR(i, T) {
        int N; cin >> N;
        ans = N; 
        fill(visit.begin(), visit.begin()+N+1, false);
        FOR(j, N) {
            cin >> pick[j];
            pick[j]--;
        }
        FOR(k, N) if (!visit[k]) dfs(k, 1);

        cout << ans << endl;
    }
   
}