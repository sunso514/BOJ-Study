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
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)



int N, K;

int broken, upLoc, downLoc;

vector<pair<int, bool>> conv;
deque<int> robot;

int BACK(int x) {
    return ((x) + (2 * N) - 1) % (2 * N);
}

int FRONT(int x) {
    return (x + 1) % (2 * N);
}

void info() {
    cout << endl << "- 컨베이어 벨트 현황 -" << endl;
    for (int i = 0; i < N * 2; i++) {
        cout << conv[(i) % (2 * N)].first;
        if (conv[(i) % (2 * N)].second == true) cout << "(R) ";
        else cout << " ";
    }
    cout << endl << "-------------" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;

    conv.resize(N * 2, { 0, false });

    broken = 0;
    upLoc = 0;
    downLoc = N - 1;

    FOR(i, N * 2) cin >> conv[i].first;
    int level = 0;
    int rsiz;

    while (broken < K) {
        level++;

        /*
        cout << "=========" << endl;
        cout << "Level : " << level << endl; 
        cout << "로봇 개수 : " << robot.size() << endl;
        */

        // 1. 벨트가 한 칸 회전한다.
        upLoc = BACK(upLoc);
        downLoc = BACK(downLoc);
        //cout << endl << "시작 지점 : " << upLoc << endl;
        //cout << "끝 지점 : " << downLoc << endl;

        rsiz = robot.size() - 1;
        for(int i = rsiz; i >= 0; i--){
            // 벨트 위에 로봇 없음 체크
            conv[robot[i]].second = false;
            if (robot[i] == downLoc) {
                robot.pop_back();
                //cout << "로봇 안착 완료 ! 남은 로봇 개수 : " << robot.size() << endl;
            }
            else conv[robot[i]].second = true;
        }

        //info();

        // 2. 앞으로 이동 가능하면 이동한다.
        rsiz = robot.size() - 1;
        //cout << "로봇 개수 : " << robot.size() << endl;
        for (int i = rsiz; i >= 0; i--) {
            //cout << robot[i] << "번에 있는 로봇 움직입니다 !  ";

            //망가져 있거나 앞에 로봇이 있는가?

            
            if (conv[FRONT(robot[i])].second == true) {
                //cout << "앞이 막혀 움직일 수 없습니다!" << endl;
                continue;
            }
            if (conv[FRONT(robot[i])].first <= 0) {
                //cout << "내구도가 부족합니다!" << endl;
                continue;
            }

            conv[robot[i]].second = false;
            robot[i] = FRONT(robot[i]);

            //cout << "로봇 위치 : " << robot[i] << endl;

            // 내구도 감소
            conv[robot[i]].first--;
            if (conv[robot[i]].first == 0) broken++;

            if (robot[i] == downLoc) robot.pop_back();
            else conv[robot[i]].second = true;
        }
        
        //info();

        // 3. 올리는 위치에 로봇을 올린다.
        if (conv[upLoc].first > 0) {
            robot.push_front(upLoc);
            conv[upLoc].second = true;
            conv[upLoc].first--;
            if (conv[upLoc].first <= 0) broken++;
        }
        
        //info();
    }
    cout << level;
}