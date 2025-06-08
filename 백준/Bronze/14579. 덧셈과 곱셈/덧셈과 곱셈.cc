#include <iostream>

using namespace std;
int main() {
    long long a, b; cin >> a >> b;
    long long sm = (1+a)*a/2;
    long long ans = sm;
    for(int i = a+1; i <= b; i++){
        
        sm += i;
        ans *= sm;
        ans %= 14579;
    }
    cout << ans;
    
}