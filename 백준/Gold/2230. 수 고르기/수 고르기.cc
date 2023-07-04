#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int lists[100005];
int mins = 100000000007;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> lists[i];
	} 
	sort(lists, lists+N);
	int end = 0;
	for (int start = 0; start < N; start++){
		while(end < N && lists[end] - lists[start] < M) end++;
		if (end == N) break;
		mins = min(mins, lists[end] - lists[start]);
	}
	cout << mins;
}