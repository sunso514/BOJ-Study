#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Loc {
	int x, count;
};

vector<bool> visit(100000, 0);
queue<Loc> que;

int N, T, G;

int command_B(int N) {
	if (N == 0) return 0;

	string tmp = to_string(N);

    // abort() 오류 해결 ( 예외처리 )
	int firstDigit = tmp[0] - '0';
	if (firstDigit == 0) {
		tmp = "9" + tmp.substr(1);
	}
	else {
		tmp[0] = (firstDigit - 1) + '0';
	}

	return stoi(tmp);
}


int bfs() {
	Loc loc;

	while (!que.empty()) {
		loc = que.front();
		que.pop();
		if (loc.x == G) return loc.count;

		visit[loc.x] = true;
		if (loc.x + 1 < 100000) {
			if (visit[loc.x + 1] == false && loc.count < T) {
				que.push({ loc.x + 1, loc.count + 1 });
			}
		}
		if (loc.x * 2 < 100000) {
			int new_X = command_B(loc.x * 2);
			if (visit[new_X] == true || loc.count >= T) continue;
			que.push({ new_X, loc.count + 1 });
		}


	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T >> G;
	que.push({ N, 0 });

	int ans = bfs();
	ans == -1 ? (cout << "ANG") : (cout << ans);

}