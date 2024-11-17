
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

int N; 


int main(void) {
    cin.tie(NULL);

    int T; cin >> T;

    vector<vector<string>> vec;

    for (int i = 0; i < T; i++) {
        vector<string> tmp;
        for (int j = 0; j < 5; j++) {
            string a; cin >> a;
            tmp.push_back(a);
        }
        vec.push_back(tmp);
    }
    
    int ans_a, ans_b;
    int minV = 1000000007;

    for (int i = 0; i < T; i++) {
        for (int j = i + 1; j < T; j++) {
            
            int count = 0;
            for (int col = 0; col < 5; col++) {
                for (int row = 0; row < 7; row++) {
                    
                    if (vec[i][col][row] != vec[j][col][row]) {
                        count++;
                    }
                }
            }
            if (minV > count) {
                minV = count;
                ans_a = i + 1;
                ans_b = j + 1;

               // cout << "TEST : " << ans_a << " " << ans_b << " " << count << endl;
            }
        }
    }
    cout << ans_a << " " << ans_b;
}