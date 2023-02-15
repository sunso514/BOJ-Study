#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

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

    bool streak = false;
    int n_streaknum = 0;
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (streak == false) {
            if (page[i] == true) continue;
            else {
                streak = true;
                answer += 7;
            }
        }
        else {
            if (page[i] == true) { 
                n_streaknum++;
                if (n_streaknum > 2) {
                    answer -= n_streaknum*2-2;
                    streak = false;
                    n_streaknum = 0;
                }
                else answer += 2;
            }
            else {
                answer += 2;
                n_streaknum = 0;
            }
        }
    }
    if (streak == true) answer -= n_streaknum*2;
    cout << answer;
}