#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s; 
    cin >> s >> s; 
    s += 'a';
    
	int p = 'a', cnt = 0, maxV = 0;
	for (auto l : s) {
		int curr = (int)l;
        
		if (curr == p + 1 || curr == p - 1) {
            cnt++;
        }
        else {
			maxV = max(maxV, cnt);
			cnt = 1;
		}
		p = curr;
	}

	if (maxV < 5) cout << "NO";
	else cout << "YES";
}