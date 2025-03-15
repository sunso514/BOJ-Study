#include <iostream>
using namespace std;
int A,B,C,ans;
int main(){
    cin >> A >> B >> C;
    
    if(C % 2) ans = A ^ B;
    else ans = A;
    
    cout << ans;
}