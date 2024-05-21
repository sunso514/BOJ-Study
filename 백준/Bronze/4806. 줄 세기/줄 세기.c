#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int count = 0;
    char ch[500];
    char *get = fgets(ch, 500, stdin);
    while(!feof(stdin)){
        count++;
        get = fgets(ch, 500, stdin);
    }
    printf("%d", count);
    return 0;
}