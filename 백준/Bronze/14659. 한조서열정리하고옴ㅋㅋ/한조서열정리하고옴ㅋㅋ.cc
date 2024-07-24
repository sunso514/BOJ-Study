/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    int N; cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }
    
    int ans = 0;
    int streak = 0;
    int val = vec[0];
    for(int i = 1; i < N; i++){
        if (val >= vec[i]){
            streak++;
            ans = max(ans, streak);
        }
        else {
            streak = 0;
            val = vec[i];
        }
    }
    cout << ans;
    return 0;
}