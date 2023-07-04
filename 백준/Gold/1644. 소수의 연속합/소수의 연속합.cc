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
#define test "test "
#define endl "\n"

using namespace std;
#define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    vector<int> era(N + 1, false);

    for (int i = 2; i <= N; i++) {
        if (era[i] == true) continue;

        for (int j = 2 * i; j <= N; j += i) {
            era[j] = true;
        }
    }
    vector<int> sosu;

    int prime_sum = 0;

    int res = 0;

    for (int i = 2; i <= N; i++) {
        
        if (era[i] == false) {
            prime_sum += i;
            //cout << i << " ";
            if (prime_sum == N) res++;
            sosu.push_back(prime_sum);
        }
    }
    //for (int i = 0; i < sosu.size(); i++) cout << sosu[i] << " ";
    //cout << endl;


    int start = 0;
    int end = 0;
    

    while (start <= end && end < sosu.size()) {
        if (sosu[end] - sosu[start] > N) {
            start++;
        }
        else if (sosu[end] - sosu[start] < N) {
            end++;
        }
        else {
            //cout << start << " " << end << endl;
            res++;
            end++;
        }
    }
    cout << res;
}