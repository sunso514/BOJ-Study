#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main (void) {
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        
        vector<string> name(N);
        vector<int> price(N);
        
        for(int i = 0; i < N; i++){
            cin >> price[i] >> name[i];
        }
        
        int maxV = -1;
        int maxN = -1;
        for(int i = 0; i < N; i++){
            if (maxV < price[i]){
                maxV = price[i];
                maxN = i;
            }
        }
        cout << name[maxN] << endl;
    }
    
}