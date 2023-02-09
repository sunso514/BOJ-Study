#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
//	vector<int> list(time);
//vector<int> list;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    queue<int> left;
    int getidx = 0;
    for (int i = 0; i < n; i++) v[i] = i+1;
    while (!v.empty()) {
        getidx = (getidx + (k - 1)) % v.size();
        left.push(v[getidx]);
        v.erase(v.begin() + getidx);
    }
    cout << "<";
    while (!left.empty()) {
        cout << left.front();
        left.pop();

        if (!left.empty())
            cout << ", ";
    }
    cout << ">";
}
