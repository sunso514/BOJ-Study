#include <stdio.h>

int main(void) {
	int a = 1, b;
	while (a != 0) {
		scanf("%d%d", &a, &b);
		if (a != 0) {
			printf("%d\n", a + b);
		}
	}
}