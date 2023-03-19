#include <iostream>

using namespace std;

int main(){
    
    int a; cin >> a;
    int time; cin >> time;
    
    int res = 0;
    for(int i = 0; i < time; i++){
        int b, c;
        cin >> b >> c;
        res += b * c;
}
    if (res == a) cout << "Yes";
    else cout << "No";
}