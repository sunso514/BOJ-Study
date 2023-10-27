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


class Sort {
	public:
		void setting(int& val) {
			for (int i = 0; i < val; i++) {
				string inp;
				cin >> inp;
				if (mp.find(inp) != mp.end()) mp[inp]++;
				else mp[inp] = 1;
			}
			vec = vector<pair<string, int>>(mp.begin(), mp.end());
		}

		string answer() {
			sort(vec.begin(), vec.end(), compare);
			return vec[0].first;
		}
	private:
		map<string, int> mp;
		vector<pair<string, int>> vec;

		static bool compare(const pair<string, int>& a, const pair<string, int>& b) {
			if (a.second == b.second) return a.first < b.first;
			return a.second > b.second;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	Sort pl;
	pl.setting(N);
	cout << pl.answer();
}