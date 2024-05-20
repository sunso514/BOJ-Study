
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

void reverse(char []);

int main() {
    // 입출력 받기
    int num;
    char get[21];
    char *name = (char*)malloc(sizeof(char)*30);
    
    scanf("%d %s", &num, get);

    // 3번 요구사항 해결 
    char buf_num[5];
    sprintf(buf_num, "%d", 1906 + num);
    strcat(name, buf_num);
    
    // 중복 확인을 위한 정수형 배열 생성 및 중복 제거
    int check_dup[30] = {0,};
    int dup_count = 4;
    for(int i = 0; get[i] != '\0'; i++){
        if (check_dup[get[i] - 'a'] == true) {
            dup_count++;
            continue;
        } 
        check_dup[get[i] - 'a'] = true;
        name[strlen(name)] = get[i];
    }
    
    // 숫자를 문자열로 변환하고 뒤에 붙이기
    char buf_dup[3];
    sprintf(buf_dup, "%d", dup_count);
    strcat(name, buf_dup);

    //printf("%s", name);
    reverse(name);
    printf("smupc_%s", name);    
    return 0;
}

void reverse(char str[]){
    for(int i = 0, j = (int)strlen(str) - 1; i < j; i++, j--){
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}