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

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;


#define X dx[i] + loc.x
#define Y dy[i] + loc.y


class Problem {
public:
	Problem(int N, int M) {
		for (int i = 0; i < N; i++) {
			string get; 
			cin >> get;
			//if (mp.find(get) != mp.end()) 
			if (get.length() >= M) mp[get]++;
		}
		vec = vector<pair<string, int>>(mp.begin(), mp.end());
	}

	void answer() {
		sort(vec.begin(), vec.end(), compare);
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i].first << endl;
		}
	}
protected:
	static bool compare(const pair<string, int>& a, const pair<string, int>& b) {
		if (a.second != b.second) {
			return a.second > b.second;
		}
		if (a.first.length() != b.first.length()) {
			return a.first.length() > b.first.length();
		}
		return a.first < b.first;
	}
private:
	map<string, int> mp;
	vector<pair<string, int>> vec;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	Problem pb(n, m);
	pb.answer();
}