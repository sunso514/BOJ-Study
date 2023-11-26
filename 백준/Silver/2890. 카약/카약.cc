#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct KY {
    int distance, team, rank;
};

bool compare(KY a, KY b) {return a.distance > b.distance;}
bool compare_by_index(KY a, KY b) {return a.team < b.team;}


int main()
{
    int R, C;
    cin >> R >> C;

    vector<KY> res;

    for (int i = 0; i < R; i++) {
        string track; cin >> track;

        int count = 0;
        int team = -1;
        for (int j = 1; j < C - 1; j++) {
            if (track[j] == '.') count++;
            else {
                team = track[j] - '0';
                break;
            }
        }
        if (team != -1) res.push_back({ count, team, 0 });
    }
    
    sort(res.begin(), res.end(), compare);
    int rank = 0;
    int last = -1;
    for (int i = 0; i < 9; i++) {
        if (last != res[i].distance) rank++;
        
        last = res[i].distance;
        res[i].rank = rank;
    }

    sort(res.begin(), res.end(), compare_by_index);
    for (int i = 0; i < 9; i++) {
        cout << res[i].rank << "\n";
    }

}