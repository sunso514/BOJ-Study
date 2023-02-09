#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int sta = a , stb = b, stc;
	while (stb != 0) { // 최대공약수
		stc = sta % stb;
		sta = stb;
		stb = stc;
	}
	cout << sta << endl;
	cout << a * b / sta;



}