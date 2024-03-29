#include <iostream>
#include <algorithm>
#include <map>

#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;
int N, D, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string S;
	cin >> N >> S >> D >> M;

	map<char, int> mp;
	mp['H'] = 0;
	mp['Y'] = 0;
	mp['U'] = 0;

	int streak = 0;
	int energy = 0;
	FOR(i, N) {
		if (S[i] == 'H' || S[i] == 'Y' || S[i] == 'U') {
			mp[S[i]]++;
			if (streak > 0) {
				energy += min(D * streak, M+D);
				streak = 0;
			}
		}
		else streak++;
	}
	if (streak > 0) energy += min(D * streak, M+D);
    
	int HYU = min(min(mp['H'], mp['U']), mp['Y']);
	(energy == 0 ? cout << "Nalmeok" : cout << energy) << endl;
	(HYU == 0 ? cout << "I love HanYang University" : cout << HYU);
}