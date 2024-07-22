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

#include <bitset>

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

struct Team {
	int number, solved, tm_score;
	int time[18];
	bool AC[18];
};

bool compare(Team &a, Team &b) {
	if (a.solved != b.solved) return a.solved > b.solved;
	if (a.tm_score != b.tm_score) return a.tm_score < b.tm_score;
	return a.number < b.number;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, Q;
	cin >> N >> M >> Q;

	vector<Team> tm(N);
	for (int i = 0; i < N; ++i) {
		tm[i].number = i + 1;
	}

	int time, team, pnum;
	string res;
	for (int i = 0; i < Q; i++) {
		cin >> time >> team >> pnum >> res;
		pnum--;
		team--;
		if (tm[team].AC[pnum] == true) continue;
		if (res == "AC") {
			tm[team].AC[pnum] = true;
			tm[team].time[pnum] += time;
			tm[team].solved++;
		}
		else tm[team].time[pnum] += 20;
	}

	// 점수 매기기
	for (int tnum = 0; tnum < N; tnum++) {
		for (int i = 0; i < 15; i++) {
			if (tm[tnum].AC[i] == true) {
				tm[tnum].tm_score += tm[tnum].time[i];
			}
		}
	}
	sort(tm.begin(), tm.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << tm[i].number << " " << tm[i].solved << " " << tm[i].tm_score << endl;
	}
}