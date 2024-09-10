/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int check(string N, int num, int pointer){
    //cout << N[pointer] << " " << pointer << " " << num << endl;
    
    string goal = to_string(num);
    for(int i = pointer; i < goal.size()+pointer; i++){
        if (N[i] != goal[i - pointer]){
            return -1;
        }
    }
    return goal.size();
}



int main()
{
    
    string N; cin >> N;
    int num = 0;
    for(int i = 0; i < N.size(); i++){
        num++;
        int size = check(N, num, i);
        
        if (size == -1){
            cout << -1;
            return 0;
        }
        i += size - 1;
    }
    cout << num;
    return 0;
}