#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<vector<bool>>> visit(202, vector<vector<bool>>(202, vector<bool>(202)));
vector<bool> check(202);
queue<vector<int>> que;

vector<int> msiz(3);

void bfs() {
	vector<int> now;

	while (!que.empty()) {
		now = que.front();
		que.pop();

		if (visit[now[0]][now[1]][now[2]]) continue;
		visit[now[0]][now[1]][now[2]] = true;
		if (now[0] == 0) check[now[2]] = true;

	

		for (int i = 0; i < 3; i++) {
			for (int j = 1; j <= 2; j++) {
				vector<int> tmp = now;
				int nxt = (i + j) % 3;

				if (now[i] + now[nxt] > msiz[nxt]) {
					tmp[i] = now[i] + now[nxt] - msiz[nxt];
					tmp[nxt] = msiz[nxt];
				}
				else {
					tmp[i] = 0;
					tmp[nxt] = now[i] + now[nxt];
				}
				que.push(tmp);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> msiz[0] >> msiz[1] >> msiz[2];

	vector<int> tmp(3);
	tmp[2] = msiz[2];

	que.push(tmp);
	bfs();

	for (int i = 0; i <= msiz[2]; i++) if (check[i] == true) cout << i << " ";
}