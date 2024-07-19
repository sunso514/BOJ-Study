#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << int(a / b)<< ".";
	a %= b;
	for (int i = 0; i <= 1000; i++)
	{
		a *= 10;
		cout << a/b;
		a = a - a / b * b;
	}
}