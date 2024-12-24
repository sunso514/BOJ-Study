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
int main(void)
{
    int N;
    string tmp="";
    
    cin>>N;
    
    for(int i=1;i<=N;i++) {
        tmp += to_string(i);
    }

    int ans = tmp.find(to_string(N));
    cout<< ans+1;
}