#include <stdio.h>
int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	if (b < 45) {
		b = 60 - (45-b);
		if (a == 0) {
			a = 23;
		}
		else {
			a--;
		}
	}
	else {
		b = b - 45;
	}
	printf("%d %d", a, b);
}