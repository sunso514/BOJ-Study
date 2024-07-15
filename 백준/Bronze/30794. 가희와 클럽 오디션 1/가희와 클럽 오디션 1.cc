#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int X;
	string S;
	cin >> X >> S;
	if (S == "miss") cout << X * 0;
	if (S == "bad") cout << X * 200;
	if (S == "cool") cout << X * 400;
	if (S == "great") cout << X * 600;
	if (S == "perfect") cout << X * 1000;
}