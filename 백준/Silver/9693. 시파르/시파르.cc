#include <iostream>

using namespace std;

int get_ans(int N) {
    int ct = 0;
    for (long long i = 5; i <= N; i *= 5) {
        ct += N / i;
    }
    return ct;
}

int main() {
    int cse = 0;
    while(true){
        cse++;
        int N;
        cin >> N;
        if (N == 0) break;
        int result = get_ans(N);
        cout << "Case #" << cse <<": " << result << "\n";
        
    }
}