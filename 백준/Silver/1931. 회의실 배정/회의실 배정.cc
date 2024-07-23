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

struct lecture {
	int start, end;
};

bool compare(lecture &a, lecture &b) {
	if (a.end != b.end) return a.end < b.end;
	return a.start < b.start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N; cin >> N;
	vector<lecture> time_table(N);
	for (int i = 0; i < N; i++) {
		cin >> time_table[i].start >> time_table[i].end;
	}
	sort(time_table.begin(), time_table.end(), compare);
	/*
	for (auto i : time_table) {
		cout << i.start << " " << i.end << endl;
	}
	cout << "\nTEST\n";
	*/
	int ans = 0;
	int now_time = -1;
	for (auto lec : time_table) {
		if (now_time > lec.start) continue;
		now_time = lec.end;
		ans++;
	}
	cout << ans;
}