#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> home;

struct location {
	int x, y;
};


bool check(location a, location b){
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;

}
int main() {
	int time, x, y;
	cin >> time;
	vector<location> coord(time);
	for (int i = 0; i < time; i++) {
		cin >> x >> y;
		coord[i] = { x, y };
	}
	sort(coord.begin(), coord.end(), check);
	for (location ct : coord) cout << ct.x << " " << ct.y << "\n";
}