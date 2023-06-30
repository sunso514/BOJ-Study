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

int N;

struct Edge {
    int send, receive;
    double cost;
};

int st_cost(Edge a, Edge b) {
    return a.cost < b.cost;
}

vector<pair<double, double>> star;
vector<int> parent(105, -1);
vector<Edge> edges;

int Find(int cord) {
    if (parent[cord] < 0) return cord;
    return parent[cord] = Find(parent[cord]);
}

bool Union(int x, int y) {
    int xp = Find(x);
    int yp = Find(y);
    
    if (xp == yp) return 0;
    if (parent[xp] > parent[yp]) parent[xp] = yp;
    else parent[yp] = xp;
    return 1;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        double a, b;
        cin >> a >> b;
        star.push_back({ a, b });
    }
    //cout << "test hello world" << endl;
    for (int i = 0; i < N; i++) {
        //cout << "I up" << " ";
        for (int j = i + 1; j < N; j++) {
            //cout << "j up " << " " << star[i].first << " " << star[j].first << " " << star[i].second << " " << star[j].second << endl;
           edges.push_back({ i, j, sqrt(pow(star[i].first - star[j].first, 2) + pow(star[i].second - star[j].second, 2)) });
        }
    }   
    //cout << endl;
    sort(edges.begin(), edges.end(), st_cost);

    /*
    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].cost << " ";
    }
    cout << endl;
    */

    double res = 0;
    int cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (Union(edges[i].send, edges[i].receive) == false) continue;

        cnt++;
        res += edges[i].cost;
        if (cnt == N - 1) break;
    }
    cout.precision(3);
    cout << res;


}