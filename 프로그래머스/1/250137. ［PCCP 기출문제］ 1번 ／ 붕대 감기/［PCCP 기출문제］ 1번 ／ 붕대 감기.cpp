#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int streak = 0;
    int point = 0;
    for (int i = 0; i < attacks[attacks.size()-1][0]+1; i++){
        if (i == attacks[point][0]){
            answer -= attacks[point][1];
            if (answer <= 0) return -1;
            streak = 0;
            point++;
        }
        else{
            streak++;
            answer = min(health, answer + bandage[1]);
            if (streak == bandage[0]){
                streak = 0;
                answer = min(health, answer + bandage[2]);
            }
        }
    }
    return answer;
}