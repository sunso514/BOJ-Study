/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    char game;
    cin >> N >> game;
    map<string, bool> m;
    
    int count = 0;
    
    for(int i = 0; i < N; i++){
        string name;
        cin >> name;
        if(m.find(name) == m.end()){
            m[name] = true;
            count++;
        }
    }
    if (game == 'Y') cout << count;
    else if (game == 'F') cout << count / 2;
    else cout << count / 3;

    return 0;
}
