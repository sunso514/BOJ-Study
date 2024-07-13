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

int N, M;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

#define X dx[i] + loc.x
#define Y dy[i] + loc.y


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string mbti;
	cin >> mbti;
	int get;
	cin >> get;

	int count = 0;
	for (int i = 0; i < get; i++) {
		string n; cin >> n;
		if (mbti == n) count++;
	}

	cout << count;
}