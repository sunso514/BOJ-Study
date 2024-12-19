#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M;
    int lst[1010] = { 0 };
    int ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        lst[M]++;
    }
    for (int i = 1; i <= 1000; i++)
        ans += min(lst[i], 2);
    cout << ans;
}