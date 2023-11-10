#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#define endl "\n"
using namespace std;


class Solver{
public:
	Solver() {
		string now = "";
	}

	void setTargetString(string N) {
		this->now = N;
	}

	string getTargetString() {
		return this->now;
	}

	string convert() {
		string tmp = "";
		string target = getTargetString();
		
		int length = target.length();
		int change_count = 0;

		for (int idx = 0; idx < target.length(); idx++) {

			// check a char in now 
			bool check = false;
			for (int i = 0; i < 7; i++) {
				if (dic[i] == target[idx]) {
					tmp += conv[i];
					check = true;
					change_count++;
					break;
				}
			}
			if (check == true) continue;

			// check \\' and \'
			if (target[idx] == '\\') {
				// if this is W
				if (target[idx + 1] == '\\') {
					tmp += 'w';
					idx += 2;
				}
				else {
					tmp += 'v';
					idx++;
				}
				change_count++;
				continue;
			}
			tmp += target[idx];
		}

		if (change_count >= tmp.length()/2.0) return "I don't understand";
		else return tmp;
	}

private:
	string now;

	char dic[7] = {'@', '[', '!', ';', '^', '0', '7'};
	char conv[7] = { 'a', 'c', 'i', 'j', 'n', 'o', 't' };
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	
	Solver sol;

	for (int i = 0; i < N; i++) {
		string inp;
		cin >> inp;

		sol.setTargetString(inp);
		sol.setTargetString(sol.convert());
		cout << sol.getTargetString() << endl;
	}

}