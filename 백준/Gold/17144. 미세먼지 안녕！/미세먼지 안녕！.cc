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

int N, M, T;

struct Location {
	int x, y, val;
};

int dx[4] = { -1 , 1, 0 , 0 };
int dy[4] = { 0, 0, 1, -1 };
int wdr[4];



queue<Location> que;
vector<vector<int>> room;
vector<Location> wind_dir;

pair<int, int> air_con = { -1,-1 };

void put_in_que() {
	FOR(i, N) FOR(j, M) {
		if (room[i][j] <= 0) continue;
		que.push({ i, j, room[i][j] });
		room[i][j] = 0;
	}
}

bool checkPassable(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	if (room[x][y] == -1) return false;
	return true;
}

void make_windway(int wx, int wy, int wdr[]) {
	for (int i = 0; i < 4; i++) {
		while (true) {
			if (checkPassable(wx + dx[wdr[i]], wy + dy[wdr[i]]) == false) {
				if (i == 3) wind_dir.push_back({ wx, wy, 5 });
				break;
			}
			if (checkPassable(wx, wy) == true) wind_dir.push_back({ wx, wy, wdr[i] });
			wx += dx[wdr[i]];
			wy += dy[wdr[i]];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> T;
	room.resize(N, vector<int>(M));
	// setting ( input ) 
	FOR(i, N) FOR(j, M) {
		cin >> room[i][j];
		if (room[i][j] == -1) air_con.first == -1 ? air_con.first = i : air_con.second = i;
	}
	
	// make wind road
	int wdr[4] = { 2, 0, 3, 1 };
	make_windway(air_con.first, 0, wdr);
	wdr[1] = 1; wdr[3] = 0;
	make_windway(air_con.second, 0, wdr);

	// wind direction debug
	//for (int i = 0; i < wind_dir.size(); i++) cout << i << " : " << wind_dir[i].x << " " << wind_dir[i].y << " " << wind_dir[i].val << endl;


	FOR(tme, T) {
		// 모든 미세먼지 위치와 양을 que에 담는다.
		put_in_que();

		// 미세먼지 확산
		while (!que.empty()) {
			Location tmp = que.front();
			que.pop();

			// amount of diffusion direction
			int dir = 0;
			for (int i = 0; i < 4; i++){
				if (checkPassable(tmp.x + dx[i], tmp.y + dy[i]) == false) continue;
				dir++;
			}
			for (int i = 0; i < 4; i++) {
				if (checkPassable(tmp.x + dx[i], tmp.y + dy[i]) == false) continue;
				room[tmp.x + dx[i]][tmp.y + dy[i]] += tmp.val / 5;
			}
			room[tmp.x][tmp.y] += tmp.val - (tmp.val / 5) * dir;
		}
		/*
		cout << endl;
		FOR(i, N) {
			FOR(j, M) cout << room[i][j] << " ";
			cout << endl;
		}*/

		// 바람이 분다.
		for (int i = wind_dir.size() - 1; i >= 0; i--) {
			Location w = wind_dir[i];

			int dust_a = room[w.x][w.y];
			room[w.x][w.y] = 0;
			if (wind_dir[i].val != 5) room[w.x + dx[w.val]][w.y + dy[w.val]] = dust_a;
		}
		
	}
	int res = 0;
	FOR(i, N) FOR(j, M) if (room[i][j] != -1) res += room[i][j];
	cout << res;
}