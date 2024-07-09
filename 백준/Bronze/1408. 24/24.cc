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

string getZero(int N) {
	if (N < 10) {
		string tmp = "0";
		tmp.push_back(N + '0');
		return tmp;
	}
	return to_string(N);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string a, b;
	cin >> a >> b;

	int atime = 0, btime = 0, tottime = 0;
	atime += (stoi(a.substr(0, 2)) * 3600) + (stoi(a.substr(3, 2))*60) + stoi(a.substr(6, 2));
	btime += (stoi(b.substr(0, 2)) * 3600) + (stoi(b.substr(3, 2)) * 60) + stoi(b.substr(6, 2));
	if (atime > btime) btime += 86400;
	tottime = btime - atime;

	//cout << tottime / 3600 << " " << tottime / 60 % 60 << " " << tottime % 60 << endl;
	cout << getZero(tottime / 3600) << ":" << getZero(tottime / 60 % 60) << ":" << getZero(tottime % 60);

	
}