#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M, i, a, c;
    int v[1010][2] = { 0 };
    char b;

    cin >> N >> M;
    for (i = 1; i <= N; i++) {
        v[i][0] = v[i][1] = -1;
    }
    for (i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        if (b == 'P') v[a][0] = c;
        else v[a][1] = c;
    }

    int ans_a = 0;
    int ans_b = 0;
    for (i = 1; i <= N; i++)
    {
        if (v[i][0] == 1 && v[i][1] == 0) ans_a++;
        if (v[i][0] != 0 && v[i][1] != 1) ans_b++;
    }
    cout << ans_a << ' ' << ans_b << "\n";
}