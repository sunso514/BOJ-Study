#include <iostream>
#include <algorithm>
#include <vector>

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
    
	int ans = 0;
	int now_time = -1;
	for (auto lec : time_table) {
		if (now_time > lec.start) continue;
		now_time = lec.end;
		ans++;
	}
	cout << ans;
}