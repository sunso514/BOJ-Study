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
//	vector<int> list(time);
//vector<int> list;

int n, m;
int res;
int graph[101][101];
//vector<vector<int>> vec;

bool dfs(int x, int y, int rgb, bool check) {
	// 그래프 밖으로 벗어나는거 방지
	if (x <= -1 || x >= n || y <= -1 || y >= n) return false;
	if (check == true) {
		if (rgb > 3) return false;
		if (graph[x][y] == rgb) {
			graph[x][y] = rgb + 3;
			dfs(x - 1, y, rgb, true);
			dfs(x, y - 1, rgb, true);
			dfs(x + 1, y, rgb, true);
			dfs(x, y + 1, rgb, true);
			return true;
		}
		else return false;
	}
	else {
		if (rgb <= 0) return false;
		if (rgb == 4 || rgb == 5) {
			if (graph[x][y] == 4 || graph[x][y] == 5) {
				graph[x][y] = -1;
				dfs(x - 1, y, rgb, false);
				dfs(x, y - 1, rgb, false);
				dfs(x + 1, y, rgb, false);
				dfs(x, y + 1, rgb, false);
				return true;
			}
			else return false;
		}
		else{
			if (graph[x][y] == rgb) {
				graph[x][y] = -1;
				dfs(x - 1, y, rgb, false);
				dfs(x, y - 1, rgb, false);
				dfs(x + 1, y, rgb, false);
				dfs(x, y + 1, rgb, false);
				return true;
			}
			else return false;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < n; j++) {
			if (a[j] == 'R') graph[i][j] = 1;
			if (a[j] == 'G') graph[i][j] = 2; 
			if (a[j] == 'B') graph[i][j] = 3;
		}
	}
	int res = 0;
	for (int row = 0; row < n; row++) {
		for (int column = 0; column < n; column++) {
			if (dfs(row, column, graph[row][column], true)) res++;
		}
	}
	cout << res << " ";
	res = 0;
	for (int row = 0; row < n; row++) {
		for (int column = 0; column < n; column++) {
			if (dfs(row, column, graph[row][column], false)) res++;
			
		}
	}
	cout << res;

	return 0;
}