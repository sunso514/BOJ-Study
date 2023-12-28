#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    cin >> N;

    for (int i = 0; i < N.length() / 2; i++) {
        if (N[i] != N[N.length() - 1 - i]) {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
    
}