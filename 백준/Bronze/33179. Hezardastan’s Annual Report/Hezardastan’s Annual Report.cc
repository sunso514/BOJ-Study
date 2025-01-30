#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++){
         int a; cin >> a;
        a--;
        ans += a / 2 + 1;
    }
    
    cout << ans;
}