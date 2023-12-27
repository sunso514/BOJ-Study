#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <deque>
#include <set>
#include <tuple>

#define test "test "
#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;


char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

bool Check(string N) {

    int vowel_streak = 0;
    int consonant_streak = 0;

    char last_word = '-';
    bool check_vowel = false;

    for (int i = 0; i < N.length(); i++) {
        //cout << last_word << " " << vowel[i] << endl; 
        if (last_word == N[i] && N[i] != 'e' && N[i] != 'o') {
            return false;
        }
        
        bool check = false;
        for (int vo = 0; vo < 5; vo++) {
            if (N[i] == vowel[vo]) {
                check = true;
                check_vowel = true;
            }
        }

        if (check == true) {
            if (consonant_streak > 0) consonant_streak = 0;
            vowel_streak++;
        }
        else {
            if (vowel_streak > 0) vowel_streak = 0;
            consonant_streak++;
        }

        if (consonant_streak >= 3 || vowel_streak >= 3) return false;

        last_word = N[i];
    }
    return (check_vowel == true) ? true : false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        string N;
        cin >> N;
        if (N == "end") break;
        cout << "<" << N << "> is ";
        if (Check(N) == false) {
            cout << "not ";
        }
        cout << "acceptable." << endl;
        

    }
}