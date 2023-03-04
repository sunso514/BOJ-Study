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
#define X l.x + dx[i]
#define Y l.y + dy[i]
#define Z l.z + dz[i]

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;

vector<string> vec;

string tmp = "";

void temp_push(string a) {
    if (a.length() > 0) {
        vec.push_back(a);
        tmp = "";
    }
}


int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    string str;
    getline(cin, str);


    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ') {
            temp_push(tmp);
            continue;
        }
        if (c == '<' || c == '>' || c == '(' || c == ')') {
            temp_push(tmp);
            tmp.push_back(c);
            temp_push(tmp);
            continue;
        }
        if (c == '&' || c == '|') {
            if (tmp.length() < 1) tmp.push_back(c);
            else{
                if (tmp.length() == 1 && tmp[0] == c) {
                    tmp.push_back(c);
                    temp_push(tmp);

                }
                else {
                    temp_push(tmp);
                    tmp.push_back(c);
                }
            }
        }
        else {
            tmp.push_back(c);
        }
        if (i == (str.length() - 1)) {
            temp_push(tmp);
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

}