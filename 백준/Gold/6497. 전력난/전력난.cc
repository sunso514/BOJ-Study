
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
#include <iomanip>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)
#define INF 1000000009

using namespace std;


struct road {
    int x, y, dist; 
};

bool compare(road& x, road& y) {
    return x.dist < y.dist;
}

int find_parent(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_parent(parent, parent[x]);  
}

bool union_nodes(vector<int>& parent, int x, int y) {
    int px = find_parent(parent, x);
    int py = find_parent(parent, y);
    if (px == py) return false; // 같은 집합이다.
    parent[py] = px;  
    return true;
}


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        int N, M;
        cin >> M >> N;
        if (N == M && N == 0) break;

        vector<int> visit(M, false);
        vector<road> roads;

        long long dist_sum = 0;
        for (int i = 0; i < N; i++) {
            int x, y, dist;
            cin >> x >> y >> dist;
            roads.push_back({ x, y, dist });
            dist_sum += dist;
        }
        sort(roads.begin(), roads.end(), compare);

        vector<int> parent(M);
        for (int i = 0; i < M; i++) parent[i] = i;

        long long mst_sum = 0;
        for (auto e : roads) {
            if (union_nodes(parent, e.x, e.y)) {
                mst_sum += e.dist;
            }
        }
        cout << dist_sum - mst_sum << "\n";

    }
    

}

