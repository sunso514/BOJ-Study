#include <bits/stdc++.h>

using namespace std;

long long lst[2];
int main(){
    cin >> lst[0] >> lst[1];
    if(!(lst[0] % 2) || !(lst[1] % 2)) cout << 0;
    else cout << min(lst[0], lst[1]);
}