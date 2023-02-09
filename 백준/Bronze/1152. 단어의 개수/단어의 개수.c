#include <stdio.h>
#include <string.h>

int main(){
    int a = 0;
    int length;
    char n[1000001];
    scanf("%[^\n]", n);
    length = strlen(n);
    if (length == 1){
        if (n[0] == ' '){
            printf("0\n");
            return 0;
        }
    }
    for(int i = 1; i < length-1; i++){
        if (n[i] == ' '){
            a++;
        }
    }
    
    printf("%d", a+1);
}