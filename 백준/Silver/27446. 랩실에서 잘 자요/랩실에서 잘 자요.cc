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

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;

int N, M;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    vector<int> page(N+1);
    for (int i = 1; i <= M; i++) {
        int a; cin >> a;
        page[a] = true;
    }

    // 1 2 3 5 6 7 8 9  1 2 3 

    bool streak = false;
    int streaknum = 0;
    int n_streaknum = 0;
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (streak == false) {
            if (page[i] == true) continue;
            else {
                //cout << i << "에서 streak 시작" << endl;
                streak = true;
                answer += 7;
            }
        }
        else {
            if (page[i] == true) { // 이미 찾은 페이지일 때
                n_streaknum++;
                if (n_streaknum > 2) {
                    answer -= n_streaknum*2-2;
                    //cout << "빼기:"<<n_streaknum*2-2 << endl;
                    streak = false;
                    streaknum = 0;
                    n_streaknum = 0;
                }
                else {
                    answer += 2;
                    //cout <<  i << "에서 더하기:2 그리고 streak은 " << n_streaknum << endl;
                }
            }
            else {
                answer += 2;
                n_streaknum = 0;
                //cout << "i :" << i << "," << answer << " " << endl;
            }
            
        }
    }
    if (streak == true) answer -= n_streaknum*2;
    
    cout << answer;
}