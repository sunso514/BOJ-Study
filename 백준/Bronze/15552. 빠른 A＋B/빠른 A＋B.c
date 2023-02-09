#include <stdio.h>

int main(void) {
	int a, b, tm;

	scanf("%d", &tm);
	for (int c = 0; c < tm; c++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}