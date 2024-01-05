#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>


using namespace std;

long long powV(long long a, long long b) {
    long long res = 1;
    for (int i = 0; i < b; i++) res *= a;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N;
    cin >> N;
    string iToBit = bitset<42>(N).to_string();
    long long res = 0;

    int now;
    for (int i = 0; i < 42; i++) {
        now = iToBit.length()-i-1;
        if (iToBit[now] == '1') {
            res += powV(3, i);
        }
    }
    cout << res;
}