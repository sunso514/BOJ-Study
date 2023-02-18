#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#define test "test "
using namespace std;
const int INF = 999999999;
int N;

typedef pair<int, int> pr;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;   
    
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cout << "Case #"<<i+1<<": " << a + b <<endl;
    }

}