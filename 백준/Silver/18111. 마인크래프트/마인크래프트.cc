#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
using namespace std;

//#define MAX 1000002 // 최대 정점의 개수
//#define INF 99999999

//    vector<int> list(time);
//vector<int> list;
//vector<vector<int>> vec;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);


    int garo, sero, inventory;
    cin >> garo >> sero >> inventory;

    int vec[501][501];
    for (int i = 0; i < garo; i++) {
        for (int j = 0; j < sero; j++) {
            cin >> vec[i][j];
        }
    }

    int resgoal = 0;
    int minheight = 999999999;
    int restime = 999999999;

    for (int h = 0; h <= 256; h++) {
        int goal = h;
        int place = 0, b_block = 0;
        for (int i = 0; i < garo; i++) {
            for (int j = 0; j < sero; j++) {
                int need = vec[i][j] - h;
                if (need < 0) place -= need;
                else if (need > 0) b_block += need;
            }
        }
        if (inventory + b_block >= place) {
            int casetime = b_block * 2 + place;
            if (casetime <= restime) {
                minheight = goal;
                restime = casetime;
            }
        }

    }
    cout << restime << " " << minheight;

} 