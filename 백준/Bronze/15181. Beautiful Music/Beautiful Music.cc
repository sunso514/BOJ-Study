#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(cin >> s && s != "#"){
        bool beaty = true;
        int cur = s[0] - 'A';
        for(int i = 1; i < s.size(); i++){
            int next = s[i] - 'A';
            while(next <= cur) next += 7;
            int diff = next - cur;
            if(diff != 2 && diff != 4 && diff != 6){
                beaty = false;
                break;
            }
            cur = next;
        }
        cout << (beaty ? "That music is beautiful." : "Ouch! That hurts my ears.") << "\n";
    }
    return 0;
}
