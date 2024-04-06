#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int aS = 0, bS = 0;
    
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        if (a > b) aS += a + b;
        else if (a < b) bS += a + b;
        else {
            aS += a;
            bS += b;
        }
    }
    cout << aS << " " << bS << endl;
}