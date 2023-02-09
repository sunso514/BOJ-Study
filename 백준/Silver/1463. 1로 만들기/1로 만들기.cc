#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int a;
    cin >> a;
    int dynamic[1000000];
    for(int i = 2; i <= a; i++) {
        dynamic[i] = dynamic[i - 1] + 1;
        if (i % 2 == 0) dynamic[i] = min(dynamic[i], dynamic[i / 2] + 1);
        if (i % 3 == 0) dynamic[i] = min(dynamic[i], dynamic[i / 3] + 1);
    }
    cout << dynamic[a];
}