
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string S;
    cin >> S;
    
    int zero = 0;
    int one = 0;
    
    for(int i = 0; i < S.length()-1; i++){
        if (S[i] != S[i+1]) (S[i] == '0') ? zero++ : one++;
    }
    cout << max(zero, one);
}
