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

struct Info {
	int num, golden, silver, bronze;
};

bool compare(Info& a, Info& b) {
	if (a.golden != b.golden) return a.golden < b.golden;
	if (a.silver != b.silver) return a.silver < b.silver;
	return a.bronze < b.bronze;
}

vector<Info> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int idx, g, s, b;
		cin >> idx >> g >> s >> b;
		vec.push_back({ idx, g, s, b });
	}
	sort(vec.begin(), vec.end(), compare);
	int rank = 1;
	for (int i = 0; i < N; i++) {
		if (vec[i].num == K) {
			cout << rank;
			exit(0);
		}
		if (i == N - 1) continue;
		if (vec[i].golden != vec[i + 1].golden || vec[i].silver != vec[i + 1].silver || vec[i].bronze != vec[i + 1].bronze) {
			rank = i + 2;
		}
	}
}