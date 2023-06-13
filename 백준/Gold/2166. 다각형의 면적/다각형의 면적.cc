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
    #define test "test "
    #define endl "\n"
    using namespace std;

    #define FOR(i, N) for(int (i) = 0; (i) < (N); (i)++)


    struct JongGang {
        long long hatda , mansae;
    };


    vector<vector<int>> graph;
    vector<vector<int>> visit;
    queue<JongGang> que;

    int N, M;
    long long CCW(JongGang a, JongGang b, JongGang c) {
        return (long long)(a.hatda * b.mansae) + (b.hatda * c.mansae) + (a.mansae * c.hatda) -
            (b.hatda * a.mansae) - (c.hatda * b.mansae) - (a.hatda * c.mansae);
    }


    int main() {
        cin.tie(0);
        ios::sync_with_stdio(0);
        vector<JongGang> lst;
        cin >> N;
        for (int i = 0; i < N; i++) {
            JongGang a;
            cin >> a.hatda >> a.mansae;
            lst.push_back(a);
        }
        double ans = 0;
        for (int i = 1; i < N - 1; i++) {
            ans += CCW(lst[0], lst[i], lst[i + 1])/double(2);
        }
        cout << fixed;
        cout.precision(1);
        cout << abs(ans);

    }