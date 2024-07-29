/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    
    long long w, h, k, t;
    cin >> w >> h>> k >> t;
    long long ans = 1;
    for(int i = 0; i < k; i++){
        long long x, y;
        cin >> x >> y;
        
        long long tmp = 1;
        ans *= (min(w, x+t) - max(tmp, x-t)+1) % 998244353;
        ans = ans % 998244353;
        ans *= (min(h, y+t) - max(tmp, y- t) + 1)% 998244353;
        ans = ans % 998244353;
    }
    
    cout << ans;
    
    
    return 0;
}