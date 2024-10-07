#include <iostream>
using namespace std;
int main(){
    int wc = 0;
    for(int i = 0; i < 6; i++){
        char io;
        cin >> io;
        if(io == 'W') wc++;
    }
    if(!wc) cout << -1;
    else if(wc >= 5) cout << 1;
    else if(wc >= 3) cout << 2;
    else cout << 3;
}