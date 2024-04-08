#include <iostream>

using namespace std;

int main(){
    int a, b, n;
    cin >> a >> b >> n;
    
    int ans = 0;
    while(n--){
        a = (a % b) * 10;
        ans = a/b;
    }
    cout << ans;
}
