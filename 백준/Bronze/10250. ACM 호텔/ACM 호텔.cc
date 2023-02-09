#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int time;
	cin >> time;
	for (int i = 0; i < time; i++) {
		int floor;
		cin >> floor;
		int room;
		cin >> room;
		int waiting;
		cin >> waiting;
		
		int rnum;
		if (waiting % floor != 0) {
			rnum = waiting / floor + 1;
			if (rnum < 10) {
				cout << waiting % floor << "0" << rnum << endl;
			}
			else {
				cout << waiting % floor << rnum << endl;
			}
		}
		else {
			rnum = waiting / floor;
			if (rnum < 10) {
				cout << floor << "0" << rnum << endl;
			}
			else {
				cout << floor << rnum << endl;
			}
			
		}

		
	}
}