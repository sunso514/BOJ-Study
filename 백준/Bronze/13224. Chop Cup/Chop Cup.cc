#include <iostream>
#include <string>
using namespace std;
int main(){
    int pos = 1;
    string s; 
    cin >> s;
    for(char c : s){
        if (c=='A') pos = pos == 1 ? 2 : pos == 2 ? 1 : pos;
        else if (c=='B') pos = pos == 2 ? 3 : pos == 3 ? 2 : pos;
        else if (c=='C') pos = pos == 1 ? 3 : pos == 3 ? 1 : pos;
    }
    cout << pos;
}
