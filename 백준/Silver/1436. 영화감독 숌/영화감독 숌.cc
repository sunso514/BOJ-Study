#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int n, m, streak;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;

    int res = 665;
    int count = 0;
    string check;
    while (true) {
        check = to_string(res);
        for (int i = 0; i < check.length() - 2; i++) {
            if (check[i] == '6' && check[i + 1] == '6' && check[i + 2] == '6') {
                count++;
                if (count == n) {
                    cout << res;
                    return 0;
                }
                break;
            }
        }
        res++;
    }
}