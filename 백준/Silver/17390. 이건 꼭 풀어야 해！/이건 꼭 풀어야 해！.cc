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
#define test "test "
#define endl "\n"

using namespace std;



vector<int> lists;
vector<int> psum;


int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        lists.push_back(a);
    }
    sort(lists.begin(), lists.end());
    int tmp = 0;
    psum.push_back(0);
    for (int i = 0; i < N; i++) {
        tmp += lists[i];
        psum.push_back(tmp);
    }
    for (int i = 0; i < M; i++) {
        int numa, numb;
        cin >> numa >> numb;
        cout << psum[numb] - psum[numa-1] << endl;
    }

}