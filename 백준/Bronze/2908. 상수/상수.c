#include <stdio.h>
#include <stdlib.h>
int main() {

    char a[4], b[4];
    scanf("%s %s", &a, &b);
    char mid;
    mid = a[0];
    a[0] = a[2];
    a[2] = mid;
    char mids;
    mids = b[0];
    b[0] = b[2];
    b[2] = mids;   
    int num1, num2;
    num1 = atoi(a);
    num2 = atoi(b);
    if (num1 > num2){
        printf("%d", num1);
    }
    else{
        printf("%d", num2);
    }
    return 0;
}