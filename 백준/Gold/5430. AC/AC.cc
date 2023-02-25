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
#define test "test "
#define endl "\n"

using namespace std;
const int INF = 999999999;

int N, M;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);



    int caseamount;
    cin >> caseamount;

    for (int i = 0; i < caseamount; i++) {
        deque<int> dq;
        bool error = false;

        string command, arr;
        int arrsiz;
        cin >> command >> arrsiz >> arr;
        
        string number;
        if (arr.size() > 2) {
            for (int j = 1; j < arr.length(); j++) {
                if (arr[j] == ',' || arr[j] == ']') {
                    dq.push_back(stoi(number));
                    number = "";
                }
                else number.push_back(arr[j]);
            }
        }
        bool reversed = false;
        for (int k = 0; k < command.length(); k++) {
            if (command[k] == 'R') reversed = reversed == false;
            else if (command[k] == 'D') {
                if (dq.empty()) {
                    error = true;
                    cout << "error" << endl;
                    break;
                }
                if (reversed == false) dq.pop_front();
                else dq.pop_back();
            }
        }
        if (error == true) continue;
        else {
            cout << "[";
            while(!dq.empty()){
                if (reversed == false) {
                    cout << dq.front();
                    dq.pop_front();
                }
                else {
                    cout << dq.back(); 
                    dq.pop_back();
                }
                if (!dq.empty()) cout << ",";
            }
            cout << "]";
        }
        cout << endl;
    }
}