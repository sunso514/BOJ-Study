#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#define test "Test "

using namespace std;

vector<long long> list;

string inttobin(unsigned int decimal) {
    string binary = bitset<60>(decimal).to_string();
    return binary;
}
void readytomod(string num, int chk) {
    int count = 0;
    while (chk > 0) {
        chk /= 2;
        if (num.back() == '1') list.push_back(pow(2, count));
        num.pop_back();
        count++;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long A, B, C;
    cin >> A >> B >> C;

    string num = inttobin(B);
    readytomod(num, B);

    int now = 0;
    int index = 0;

    vector<long long> mods;
    long long modres = A % C;
    while (1) {
        int check = pow(2, now);
        if (list[index] == check) {
            mods.push_back(modres);
            index++;
        }
        if (check == list.back()) break;
        now++;
        modres *= modres;
        modres = modres % C;
    }
    // A B C D E 가 있으면
    // ( (A * B) mod N ) * C ) mod N . . .
    long long res = mods[0];
    for (int i = 0; i < index - 1; i++) {
        res *= mods[i + 1];
        res = res % C;
    }
    cout << res % C;
}