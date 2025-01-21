#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>

using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string N; 
    getline(cin, N);

    stack<char> rev;
    bool prot = false;

    string ans = "";

    for (char a : N) {
        if (a == '<') {
            prot = true;
            while (!rev.empty()) {
                cout << rev.top();
                rev.pop();
            }
            cout << "<";
            continue;
        }
        else if (a == '>') {
            prot = false;
            cout << ">";
            continue;
        }
        else if (a == ' ') {
            if (prot == false) {
                while (!rev.empty()) {
                    cout << rev.top();
                    rev.pop();
                }

                cout << " ";
                continue;
            }
        }

        if (prot == false) rev.push(a);
        else cout << a;
    }
    while (!rev.empty()) {
        cout << rev.top();
        rev.pop();
    }
}
    