
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <deque>
#include <set>
#include <tuple>

#include <bitset>

#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

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
    