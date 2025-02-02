#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define endl "\n"
using namespace std;


bool checkF(int N, int size) {
    string num = "";
    string tmp = to_string(N);

    // 000121을 int로 변환하면 000이 사라지므로 이를 채워줌
    for (int i = 0; i < size - tmp.length(); i++) {
        num += "0";
    }
    num += tmp;
    
    // 앞, 뒤를 하나씩 조회하며 가운데로 나아감
    int s = num.length();
    for (int i = 0; i < s / 2; i++) {
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
    