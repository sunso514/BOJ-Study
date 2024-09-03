#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    
    vector<long long> vec(10001, 0);
    
    for(int i = 0; i <N; i++){
        int a; cin >> a;
        vec[a]++;
    }
    for(int i = 1; i < 10001; i++){
        for(int j = 0; j < vec[i]; j++){
            cout << i << "\n";
        }
    }
    

}