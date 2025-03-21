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

#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N, S, R;
char ty;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin >> N >> S >> R;
	
	vector<int> broke(N+1);
	vector<int> have(N+1);
	int ans = 0;
	
	for(int i = 0; i < S; i++){
		int a; cin >> a;
		broke[a] = 1;
	}
	for(int i = 0; i < R; i++){
		int a; cin >> a;
		have[a]++;
		if (broke[a] == 1){
			have[a] = 0;
			broke[a] = 0;
		}
	}
	
	for(int i = 1; i <= N; i++){
		if (broke[i] == 0) continue;
		
		for(int j = -1; j <= 1; j++){
			if (have[i+j] > 0){
				have[i+j]--;
				broke[i] = 0;
				break;
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		if (broke[i] == 1) ans++;
	}
	
	cout << ans;
	
}