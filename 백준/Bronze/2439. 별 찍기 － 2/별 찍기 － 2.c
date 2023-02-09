#include <stdio.h>

int main() {
    int n; // 별 개수 ( line )
    scanf("%d", &n); 
    int a = n-1; // spacebar 개수수
    int b = 1;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < a; j++){
            printf(" ");
        }
        for(int p = 0; p < b; p++){
            printf("*");
        }
        a--;
        b++;
        printf("\n");
    }

    return 0;
}