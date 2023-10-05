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

int N, M;


struct serial {
	string name;
	int value;
};


bool compare(serial &a, serial &b){
	if (a.name.length() != b.name.length()) {
		return a.name.length() < b.name.length();
	}
	if (a.value != b.value) {
		return a.value < b.value;
	}
	return a.name < b.name;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	

	cin >> N;
	vector<serial> str;



	FOR(i, N) {
		string abc; cin >> abc;
		int val = 0;
		FOR(j, abc.size()) {
			if (abc[j] < 65) val += abc[j] - '0';
		}
		str.push_back({ abc, val });
	}
	sort(str.begin(), str.end(), compare);
	FOR(i, N) cout << str[i].name << endl;
}