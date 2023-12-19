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
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N, W;

struct Info {
    int size, freeze, start_date, fail_count;
    string name;
};

bool compare(Info& a, Info& b) {
    if (a.size != b.size) return a.size > b.size;
    if (a.freeze != b.freeze) return a.freeze < b.freeze;
    if (a.start_date != b.start_date) return a.start_date < b.start_date;
    if (a.fail_count != b.fail_count) return a.fail_count < b.fail_count;
    return a.name < b.name;

}

void changeBest(Info& userRes, Info now) {
    if (userRes.size > now.size) return;
    else if (userRes.size < now.size) userRes = now;
    else {
        if (userRes.freeze < now.freeze) return;
        else if (userRes.freeze > now.freeze) userRes = now;
        else {
            if (userRes.start_date < now.start_date) return;
            else if (userRes.start_date > now.start_date) userRes = now;
            else {
                if (userRes.fail_count < now.fail_count) return;
                else if (userRes.fail_count > now.fail_count) userRes = now;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;
    vector<Info> res;

   FOR(ord, N) {
       Info userRes = { 0, 0, 0, 0, "None"};

        cin >> userRes.name;

        vector<string> board(7);
        FOR(i, 7) cin >> board[i];

        int size = 0;
        int freeze = 0;
        int start_date = 0;

        int date_count = 0;
        FOR(j, W) {
            FOR(i, 7) {
                if (board[i][j] == 'O') {
                    if (size == 0) start_date = date_count;
                    size++;
                    changeBest(userRes, { size, freeze, start_date, userRes.fail_count, userRes.name });
                }
                else if (board[i][j] == 'F') {
                    if (size != 0) freeze++;
                }
                else if (board[i][j] == 'X') {
                    userRes.fail_count++;
                    size = 0;
                    freeze = 0;
                }
                date_count++;
            }
        }
        res.push_back(userRes);
    }
    sort(res.begin(), res.end(), compare);
    //FOR(i, res.size()) cout << res[i].name << " size:" << res[i].size << " freeze:" << res[i].freeze << " start_date" << res[i].start_date << endl;
    
    int rank = 1;
    FOR(i, res.size()) {
        if (i != 0) {
            if (res[i].fail_count != res[i - 1].fail_count || res[i].size != res[i - 1].size || res[i].start_date != res[i - 1].start_date || res[i].freeze != res[i - 1].freeze) {
                rank++;
            }
        }
        cout << rank << ". " << res[i].name << endl;
    }
}