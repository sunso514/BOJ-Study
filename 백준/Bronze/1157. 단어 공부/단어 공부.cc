#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	string word;
	cin >> word;
	int size = word.length();
	int amount[27] = { 0 };
	int streak = 0;
	int num = 0;
	int max = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 26; j++) {
			if (word[i] - 65 < 32) { // 대문자일 때
				if (word[i] - 65 == j) {
					amount[j]++;
				}
			}
			else {
				if (word[i] - 97 == j) {
					amount[j]++;
				}
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		//cout << i << "번째 결과 :" << amount[i] << " " << streak << " "<< max;
		if (amount[i] > max) {
			max = amount[i];
			num = i;
			streak = 0;
		}
		else if (amount[i] == max) {
			streak++;
		}
		else {

		}
	}
	if (streak != 0) {
		cout << "?";
	}
	else {
		string res;
		res = 'A' + num;
		cout << res;
	}
	

}