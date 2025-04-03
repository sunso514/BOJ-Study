#include <iostream>
#include <sstream>
using namespace std;

char decode_word(string word) {
    int sum = 0;
    for (char c : word) {
        sum += c - 'a';
    }
    int mod = sum % 27;
    if (mod == 26) return ' ';
    else return 'a' + mod;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;
        string result = "";
        while (ss >> word) {
            result += decode_word(word);
        }

        cout << result << endl;
    }
}
