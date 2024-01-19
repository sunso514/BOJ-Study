#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<vector<int>> graph;
vector<vector<int>> visit;
vector<int> gsize(1);

int check_size = 0;
int dfs(int x, int y, int code){
    visit[x][y] = code;
    check_size++;
    for(int i = 0; i < 4; i++){
        int t_x = x + dx[i];
        int t_y = y + dy[i];
        if ((t_x >= 0 && t_y >= 0 && t_x < N && t_y < M) && (graph[t_x][t_y] == 1 && visit[t_x][t_y] == 0)){
            dfs(t_x, t_y, code);
        }
    }
    return check_size;
}


int solution(vector<vector<int>> land) {
    int answer = 0;
    N = land.size();
    M = land[0].size();
    
    graph = land;
    visit.resize(N, vector<int>(M));

    int id = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (land[i][j] == 1 && visit[i][j] == 0){
                check_size = 0;
                gsize.push_back(dfs(i, j, id));
                id++;
            }
        }
    }
    
    set<int> st;
    int maxv = 0;
    for(int j = 0; j < M; j++){
        int tmp_mv = 0;
        for(int i = 0; i < N; i++){
            if (visit[i][j] > 0){
                st.insert(visit[i][j]);
            }
        }
        for (auto it = st.begin(); it != st.end(); ++it) tmp_mv += gsize[*it];
        maxv = max(tmp_mv, maxv);
        st.clear();
    }

    return maxv;
}