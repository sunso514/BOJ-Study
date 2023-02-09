#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>

using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int a;
	cin >> a;

	// line 1.
	if (a == 0 || a == 2 || a == 3 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9) {
		cout << " * * *" << endl;
	}
	else cout << endl;
	
	// line 2-4.
	if (a == 0 || a == 4 || a == 8 || a == 9) for (int i = 0; i < 3; i++)cout << "*     *" << endl;
	else if (a == 1 || a == 2 || a == 3 || a == 7) for (int i = 0; i < 3; i++)cout << "      *" << endl;
	else for (int i = 0; i < 3; i++)cout << "*" << endl;
	
	// line 5.
	if (a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 8 || a == 9) cout << " * * *" << endl;
	else cout << endl;

	// line 5~7.
	if (a == 0 || a == 6 || a == 8) for (int i = 0; i < 3; i++)cout << "*     *" << endl;
	else if (a == 1 || a == 9 || a == 3 || a == 7 || a == 5 || a == 4) for (int i = 0; i < 3; i++)cout << "      *" << endl;
	else for (int i = 0; i < 3; i++)cout << "*" << endl;

	//line 8.
	if (a == 2 || a == 3 || a == 5 || a == 6 || a == 8 || a == 0 || a == 9) cout << " * * *" << endl;
}