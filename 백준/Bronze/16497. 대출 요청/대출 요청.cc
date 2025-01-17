
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
    ios_base::sync_with_stdio(false);
    
    int N; cin >> N;
    int books[32] = { 0 };
    int book = 0;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        for (int j = a; j < b; j++) {
            books[j]++;
            book = max(books[j], book);
        }
    }
    int K; cin >> K;
    cout << (K >= book);
}
    