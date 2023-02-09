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
int baecuamount;
int vec[51][51];
//vector<vector<int>> vec;

bool dfs(int x, int y) {
	// 그래프 밖으로 벗어나는거 방지
	if (x <= -1 || x >= n || y <= -1 || y >= m) return false;
	// 첫 방문 확인
	if (vec[x][y] == 1) {

		vec[x][y] = 0; // 방문 불가 설정
		// 가능한 곳들 모두 방문
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true; // 모두 탐색 끝냈습니다 ( true 반송 )
	}

	return false;

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int time;
	cin >> time;
	for (int i = 0; i < time; i++) {
		cin >> n >> m;
		
		cin >> baecuamount;
		vec[n + 1][m + 1] = { 0 };
		//vector<vector<int>> vec(n+1, vector<int>(m+1, 0));

		for (int j = 0; j < baecuamount; j++) {
			int seta, setb;
			cin >> seta >> setb;
			vec[seta][setb] = 1;
		}
		/*
		for (int nono = 0; nono < n; nono++) {
			for (int please = 0; please < m; please++) {
				cout << vec[nono][please];
			}
			cout << endl;
		}
		*/
		int res = 0;
		for (int row = 0; row < n; row++) {
			for (int column = 0; column < m; column++) {
				if (dfs(row, column)) {
					res++;
				}
			}
		}

		cout << res << "\n";
	}

	return 0;
}