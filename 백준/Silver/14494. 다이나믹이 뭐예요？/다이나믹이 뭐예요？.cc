#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    int dx[3] = { -1, -1, 0 };
    int dy[3] = { -1, 0, -1 };

    vector<vector<int>> vec(N, vector<int>(M, 0));
    vec[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 3; k++) {
                int tmp_x = i + dx[k];
                int tmp_y = j + dy[k];

                if (tmp_x < 0 || tmp_y < 0 || tmp_x >= N || tmp_y >= M) continue;

                vec[i][j] = (vec[tmp_x][tmp_y] + vec[i][j]) % 1000000007;
            }
        }
    }
    cout << vec[N - 1][M - 1];
}