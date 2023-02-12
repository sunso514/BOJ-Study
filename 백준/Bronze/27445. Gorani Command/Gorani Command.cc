#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int c, g;
	cin >> c >> g;
	int mingaro = 100000;
	int minx = 0;
	int minsero = 100000;
	int miny = 0;
	for (int i = 1; i <= c; i++){
		int a;
		cin >> a;
		if (minsero > a){
			miny = i;
			minsero = a;
		}
		if ( i == c){
			if (mingaro > a){
				minx = 1;
				mingaro = a;
				}			
		}
	}
	for (int i = 2; i <= g; i++){
		int a;
		cin >> a;
		if (mingaro > a){
			minx = i;
			mingaro = a;
		}
	}
	cout << miny << " " << minx;
}