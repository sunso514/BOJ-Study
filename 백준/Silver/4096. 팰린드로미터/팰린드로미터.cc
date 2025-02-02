
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


bool checkF(int N, int size) {
    string num = "";
    string tmp = to_string(N);
    for (int i = 0; i < size - tmp.length(); i++) {
        num += "0";
    }
    num += tmp;
    
    int s = num.length();
    for (int i = 0; i < s / 2; i++) {
        //cout << num[i] << " " << num[s-1-i] << endl;
        if (num[i] != num[s - 1 - i]) return false;
    }
    return true;
}




int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    while (true) {

        // 숫자가 0으로 시작하면 자동으로 0이 지워지기 때문에 string으로 받고 size를 받음
        string get; cin >> get;
        int size = get.size();

        if (get == "0") break;
        
        int count = 0;
        int N = stoi(get);
        while (true) {
            if (checkF(N, size) == true) break;
            N++;
            count++;
        }
        cout << count << endl;
    }
}
    