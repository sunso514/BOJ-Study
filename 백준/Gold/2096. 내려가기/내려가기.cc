
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <bitset>
#define test "Test "

using namespace std;

//#define MAX 100001 // 최대 정점의 개수
//#define INF 99999999

//vector<int> list;


int N;

int maxn = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    vector<long long> dpmin;
    vector<long long> dpmax;

    for (int i = 0; i < 3; i++) {
        long long a; cin >> a;
        dpmax.push_back(a);
        
        dpmin.push_back(a);
        if (N == 1) {
            long long resmax = -1;
            long long resmin = 100000000;
            if (resmax < a) resmax = a;
            if (resmin > a) resmin = a;
        }
    }

    vector<long long> input(3);
   
    
    for (int i = 1; i < N; i++) {
        cin >> input[0] >> input[1] >> input[2];
        vector<long long> temp(3);
        copy(input.begin(), input.end(), temp.begin());
       
        temp[0] = input[0] + max(dpmax[0], dpmax[1]);
        temp[1] = input[1] + max(dpmax[2], max(dpmax[0], dpmax[1]));
        temp[2] = input[2] + max(dpmax[1], dpmax[2]);

        //cout << i << "번째 실행 : " << temp[0] << " " << temp[1] << " " << temp[2] << endl;

        for (int i = 0; i < 3; i++) dpmax[i] = temp[i];
        

        //Get Min
        copy(input.begin(), input.end(), temp.begin());
        temp[0] = input[0] + min(dpmin[0], dpmin[1]);
        temp[1] = input[1] + min(dpmin[2], min(dpmin[0], dpmin[1]));
        temp[2] = input[2] + min(dpmin[1], dpmin[2]);
        for (int i = 0; i < 3; i++) dpmin[i] = temp[i];
    }
    cout << max(dpmax[2], max(dpmax[0], dpmax[1])) << " ";
    cout << min(dpmin[2], min(dpmin[0], dpmin[1]));

    

}