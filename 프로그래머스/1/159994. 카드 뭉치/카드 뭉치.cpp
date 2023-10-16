#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int c1_pot = 0;
    int c2_pot = 0;
    
    for(int i = 0; i < goal.size(); i++){
        if(cards1[c1_pot] == goal[i]){
            c1_pot++;
        }
        else if(cards2[c2_pot] == goal[i]){
            c2_pot++;
        }
        else {
            answer = "No";
            break;
        }
    }
    return answer;
}