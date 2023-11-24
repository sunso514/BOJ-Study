/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct JongGang{
  string name;
  int day, month, year;
};

bool compare(JongGang haja, JongGang please){
    if (haja.year != please.year) return haja.year > please.year;
    
    if (haja.month != please.month) return haja.month > please.month;
    
    return haja.day > please.day;
    
    
}


int main()
{
    
    int N; cin >> N;
    vector<JongGang> please;
    for (int i = 0; i < N; i++){
        string name;
        int day, month, year;
        cin >> name >> day >> month >> year;
        please.push_back({name, day, month, year});
    }
    sort(please.begin(), please.end(), compare);
    cout << please.front().name << "\n";
    cout << please.back().name;
    

}
