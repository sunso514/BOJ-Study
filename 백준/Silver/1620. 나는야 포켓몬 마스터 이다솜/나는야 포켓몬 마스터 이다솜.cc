#include <iostream>;
#include <cctype>;
#include <string>
#include <algorithm>;
#include <map>

using namespace std;
string mon[100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	map<string, int> map;

	int n, m;
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> mon[i];
		map.insert(make_pair(mon[i], i));
	}
	string input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (isdigit(input[0]) != 0) {
			//숫자를 입력받은 경우
			int ct = stoi(input);
			cout << mon[ct] << "\n";
		}
		else {
			//문자를 입력받은 경우
			auto index = map.find(input);
			cout << index->second << "\n";
		}
	}
}