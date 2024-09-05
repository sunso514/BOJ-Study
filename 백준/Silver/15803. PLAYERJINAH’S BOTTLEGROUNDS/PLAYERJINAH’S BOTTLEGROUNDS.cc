#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
struct poly{
    double x, y;
};

int main(){
    poly a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if (a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - c.x * b.y - b.x * a.y == 0) cout << "WHERE IS MY CHICKEN?";
	else cout << "WINNER WINNER CHICKEN DINNER!";
}