#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;


struct sign {
    int D, R, G; // D : location, R, G : red/green light duration 
};

bool compare(sign& a, sign& b) {
    if (a.D <= b.D) return true;
    return false;
}
int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, L; cin >> N >> L;
    deque<sign> signs;
    for (int i = 0; i < N; i++) {
        int d, r, g; cin >> d >> r >> g;
        signs.push_back({ d, r, g });
    }

    sort(signs.begin(), signs.end(), compare);
    signs.push_back({ 100000, 1, 1 });

    int loc, time;
    loc = time = 0;

    while (loc < L) {
        bool pass = true;
        if (signs.front().D == loc) {
            sign i = signs.front();
            //신호등 걸리는지 체크
            int total = i.G + i.R;
            int tmp_t = i.R - (time % total);
            
            //빨간 불
            if (tmp_t > 0) {
                time += tmp_t;
                continue;
            }
            else signs.pop_front();
            
        }
        time++;
        loc++;
    }
    std::cout << time;
}
    