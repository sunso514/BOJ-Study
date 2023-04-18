
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

#define FOR(i,N) for(int (i) = 0; (i) < (N); (i)++)
#define test "test "
#define endl "\n"
using namespace std;

struct plotInfo { // N : nourishment , NPY : nourishment per year
    vector<int> trees;
    int amount, N, NPY;
};

struct Location {
    int x, y;
};

vector<vector<plotInfo>> plot;

int N, M, K;

#define TREE plot[i][j].trees

#define X i + dx[mov]
#define Y j + dy[mov]
int dx[8] = { -1, 1, -1, 1, -1, 1, 0, 0 };
int dy[8] = { 0, 0, -1, 1, 1, -1, -1, 1 };


bool checkVoid(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) return false;
    return true;
}

void SpringSummer() {
    
    FOR(i, N) FOR(j, N) {
        if (TREE.size() == 0) continue;
        int siz = TREE.size();
        int testv = 0;
        /*
        cout << "====== 나무 먹이 감지 " << "( " << i << " " << j << " ) =======" << endl;
        cout << "양분 수 : " << plot[i][j].N << endl;
        cout << "각 나무 나이 : ";
        FOR(tmp, TREE.size()) {
            cout << TREE[tmp] << " ";
        }
        cout << endl;
        */
        for (int k = 0; k < TREE.size(); k++) {
            if (TREE[k] <= plot[i][j].N) { // 나무 밥 먹기
                plot[i][j].N -= TREE[k];
                TREE[k]++;
            }
            else { //오름차순 정렬이기 때문에 못먹으면 뒤에도 다 못먹음
                for (int tmp = siz-1; tmp >= k; tmp--) {
                    plot[i][j].N += TREE[tmp] / 2;
                    TREE.pop_back(); // 나무 사망...
                    //cout << "나무 사망! ㅠㅠ 남은 양분 : " << plot[i][j].N << endl;
                }
                break;
            }
        }
        //cout << "최종 남은 양분 : " << plot[i][j].N << endl;
        //cout << "=================" << endl;
    }
    return;
}

void Fall() {
    FOR(i, N) FOR(j, N) {
        if (TREE.size() == 0) continue;
        for (int k = 0; k < TREE.size(); k++) {
            if (TREE[k] % 5 != 0) continue; // 5의 배수 체크
            for (int mov = 0; mov < 8; mov++) {
                if (!checkVoid(X, Y)) continue;
                plot[X][Y].trees.push_back(1);
            }
        }
    }
    FOR(i, N) FOR(j, N) sort(TREE.begin(), TREE.end());
    return;
}

#define WINTER FOR(i, N) FOR(j, N) plot[i][j].N += plot[i][j].NPY

int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    plot.resize(N, vector<plotInfo>(N)); // 초기 양분 설정
    FOR(i, N) FOR(j, N) {
        plot[i][j].N = 5; // 기본 양분 설정
        cin >> plot[i][j].NPY; // 연간 양분 설정
    }
    FOR(i, M) { // 나무 심기
        int a, b, c; cin >> a >> b >> c;
        plot[a - 1][b - 1].trees.push_back(c);
    }
    FOR(i, N) FOR(j, N) sort(TREE.begin(), TREE.end()); // 나무 나이 오름차순 정렬

    for (int i = 0; i < K; i++) { // K년 나무 시뮬레이터
        //cout << i+1 << " 번 째 여름이 찾아왔다!" << endl;
        SpringSummer();
        Fall();
        WINTER;
    }
    
    int ans = 0;
    FOR(i, N) FOR(j, N) ans += TREE.size();
    cout << ans;
}