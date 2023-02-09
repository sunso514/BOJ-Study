#include <stdio.h>
int main(void) {
	int a;
	int res = 1;
	scanf("%d", &a);
	while (a > 0) {
		res = res * a;
		a--;
	}
	printf("%d", res);
}