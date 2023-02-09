#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int distance[100001];
	int price[100001];
	distance[0] = 0;
	int allofdis = 0;
	long long min = 1000000000;
	int whereismin = 0;
	for (int i = 1; i < n; i++) { // 도시 별 이동 거리 및 총 이동거리 기록
		cin >> distance[i];
		allofdis += distance[i];
	}
	for (int i = 0; i < n; i++) { // 도시 별 기름 가격 입력
		cin >> price[i];
		if (price[i] < min) {
			min = price[i]; // 가장 낮은 기름 가격 조회
			whereismin = i;
		}
	}
	long long biyong = price[0] * distance[1];
	allofdis -= distance[1];
	min = price[0];
	for (int i = 1; i < whereismin; i++) {
		if (min < price[i]) {
			biyong += min * distance[i+1];
			allofdis -= distance[i+1];
		}
		else {
			min = price[i];
			biyong += min * distance[i + 1];
			allofdis -= distance[i + 1];
		}
	}
	for (int i = whereismin; i <= n; i++) {
		if (whereismin = i) {
			biyong += price[i] * allofdis;
			cout << biyong;
			return 0;
		}
	}
}