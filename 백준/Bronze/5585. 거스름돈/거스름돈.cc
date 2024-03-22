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

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

#define TEST cout << "test\n";
#define X2 (fb.x + (dx[fb.direction] == -1 ? N - 1 : dx[fb.direction]) * fb.speed) % N
#define Y2 (fb.y + (dy[fb.direction] == -1 ? N - 1 : dy[fb.direction]) * fb.speed) % N


int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1 , -1, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N = 0;
	cin >> N;

	N = 1000 - N;


	int count = 0;
	
	int a[6] = { 500, 100, 50, 10, 5, 1 };
	
	for (int i = 0; i < 6; i++) {
		while (N >= a[i]) {
			N -= a[i];
			count++;
		}
	}
	cout << count;
	
}