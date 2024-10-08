#include <iostream>
#include <string>
#include <vector>
using namespace std;

string all_alpa = "abcdefghijklmnopqrstuvwxyz";

int main(void) {
    int N;
    vector<int> alpa(26);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		alpa[s[0] - 'a']++;
	}
	bool p = true;
	for (int i = 0; i < 26; i++) {
		if (alpa[i] >= 5) {
			cout << all_alpa[i];
			p = false;
		}
	}
	if (p) cout << "PREDAJA";
}