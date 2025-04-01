
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
#include <iomanip>

#include <bitset>


#define debug_msg cout << "Test";
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;



int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    while (cin >> N && N != -1) {
        vector<int> div;
        int sum = 0;

        for (int i = 1; i <= N / 2; ++i) {
            if (N % i == 0) {
                div.push_back(i);
                sum += i;
            }
        }

        if (sum == N) {
            cout << N << " = ";
            for (int i = 0; i < div.size(); ++i) {
                cout << div[i];
                if (i != div.size() - 1)
                    cout << " + ";
            }
            cout << endl;
        }
        else cout << N << " is NOT perfect." << endl;
    }
}
