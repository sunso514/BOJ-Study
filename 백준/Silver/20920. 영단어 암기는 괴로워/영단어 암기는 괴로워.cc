#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define endl "\n"

using namespace std;

class Problem {
public:
	Problem(int N, int M) {
		for (int i = 0; i < N; i++) {
			string get; 
			cin >> get;
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