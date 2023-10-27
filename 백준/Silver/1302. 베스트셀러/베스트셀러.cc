#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Problem {
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

	Problem pl;
	pl.setting(N);
	cout << pl.answer();
}