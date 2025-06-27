#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    
    int ans_hour = 0;
    
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        ans_hour += (a + 8);
    }
    ans_hour -= 8;
    cout << (ans_hour / 24) << " " << (ans_hour % 24);
    
    
}