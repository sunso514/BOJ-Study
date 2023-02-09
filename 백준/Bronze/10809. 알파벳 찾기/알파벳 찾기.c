// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    char s[100] = {0};
    scanf("%s", s);
    for(int i = 97; i < 123; i++){
        int j = 0;
        while (s[j] != 0) {
            if(s[j] == (char)i){
                break;
            }
            else{
                j++;
            }
        }
        if(s[j] == (char)i){
            printf("%d ", j);
        }
        else{
            printf("-1 ");
        }

    
    }

    return 0;
}