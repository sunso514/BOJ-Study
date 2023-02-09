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
	int time, goal;
	cin >> time >> goal;
	int coin[10];
	for (int i = 0; i < time; i++) {
		cin >> coin[i];
	}
	int count = 0;
	int gcoin = 0;
	while(goal > 0){
		int nanu = 100000001;
		for (int i = 0; i < time; i++) {
			if (goal / coin[i] <= nanu && goal/coin[i] > 0) {
				nanu = goal / coin[i];
				gcoin = coin[i];
			}
			
		}
		count += nanu;
		goal -= gcoin * nanu;
	}
	cout << count;

}