#include <bits/stdc++.h>
using namespace std;

#define MAX 2001

int main(){
    bool ft[MAX][MAX];
    for(int i = 0; i < 2001; ++i){
        for(int j = 0; j < 2001; ++j){
            ft[i][j] = 0;
        }
    }
    int x = 1000;
    int y = 1000;
    int ct = 1;
    int l;
    
    string msg;
    ft[x][y] = 1;
    cin >> l >> msg;
    for(auto i : msg){
        if (i == 'E') ++x;
        else if (i == 'W') --x;
        else if (i == 'S') --y;
        else if (i == 'N') ++y;
        if (ft[x][y] == 0) {
            ft[x][y] = 1;
            ++ct;
        }
    }
    cout << ct;
}