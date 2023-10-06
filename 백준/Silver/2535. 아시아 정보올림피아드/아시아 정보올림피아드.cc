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

struct Data {
	int country, number, score;
};


bool compare(Data& a, Data& b) {
	return a.score > b.score;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	vector<Data> vec(N);
	vector<int> medal(N);
	FOR(i, N) {
		cin >> vec[i].country >> vec[i].number >> vec[i].score;
	}

	sort(vec.begin(), vec.end(), compare);
	
	int count = 0;
	FOR(i, N) {
		if (count == 3) break;
		if (medal[vec[i].country-1] > 1) continue;
		cout << vec[i].country << " " << vec[i].number << endl;
		medal[vec[i].country - 1]++;
		count++;
	}
	return 0;
}