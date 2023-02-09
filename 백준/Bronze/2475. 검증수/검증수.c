#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
	int a,b,c,d,e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    a = pow(a, 2);
    b = pow(b, 2);
    c = pow(c, 2);
    d = pow(d, 2);
    e = pow(e, 2);
    e = (a+b+c+d+e)%10;
    printf("%d", e);
}