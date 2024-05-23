#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    
    scanf("%d %d", &N, &M);
    int *arr = (int *)malloc((N+1)*sizeof(int));
    
    for(int i = 0; i < M; i++){
        int k, s, e;
        scanf("%d %d %d", &k, &s, &e);
        if (s >= arr[k-1]) {
            printf("YES\n");
            arr[k-1] = e;
        }
        else printf("NO\n");
    }
    
    
    return 0;
}