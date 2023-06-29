#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>


using namespace std;

int maxV = 1000000007;
int N;
string bulb, goal;


void start(bool first) {
    string nowB = bulb;
    
    int s_count = 0;
    if (first == true) {
        nowB[0] = (nowB[0] == '0') ? '1' : '0';
        nowB[1] = (nowB[1] == '0') ? '1' : '0';
        s_count++;
    }

    for (int i = 1; i < N; i++) {
        if (nowB[i - 1] == goal[i - 1]) continue;

        nowB[i - 1] = (nowB[i - 1] == '0') ? '1' : '0';
        nowB[i] = (nowB[i] == '0') ? '1' : '0';
        if (i != N - 1) nowB[i + 1] = (nowB[i + 1] == '0') ? '1' : '0';
        s_count++;
    }
    //cout << "debug : " << nowB << endl;
    if (nowB == goal) maxV = min(maxV, s_count);
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> bulb >> goal;

    // 1번 전구를 킬 경우
    start(true);
    // 아닐 경우
    start(false);
    if (maxV == 1000000007) cout << -1;
    else cout << maxV;
    
}