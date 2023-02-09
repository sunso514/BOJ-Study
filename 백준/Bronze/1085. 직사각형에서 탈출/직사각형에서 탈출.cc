#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x,y,w,h;
    int xo, xoo;
    cin >> x >> y >> w >> h;
    xo = min(x,y);
    xoo = min(w-x,h-y);
    cout << min(xo,xoo);
}