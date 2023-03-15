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
#define test "test "
#define endl "\n"

using namespace std;

struct Location {
    double x, y;
};

vector<Location> graph;

int N, M;

int bSearch(double len) {
    int low = 0;
    int high = N-1;
    int mid;
    while (graph[low].x < graph[high].x) {
        mid = (low + high) / 2;
        if (graph[mid].x < len) low = mid + 1 ;
        else high = mid;
    }
   
    if (graph[mid].x > len) mid--;
    if (graph[mid].y == graph[mid + 1].y) return 0;
    else if (graph[mid].y < graph[mid + 1].y) return 1;
    else return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;


    for (int i = 0; i < N; i++) {
        double a, b;
        cin >> a >> b;
        graph.push_back({ a, b });
    }
    cin >> M;
    
    for (int i = 0; i < M; i++) { 
        double a; cin >> a;
        cout << bSearch(a) << endl;
    }


}