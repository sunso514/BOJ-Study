#include <stdio.h>

int main(void) {
	int sum=0;
	int count = 0;
	scanf("%d", &count);
	char str[101];
	scanf("%s", str);
	for (int i = 0; i < count; i++) {
		sum += str[i] - '0';
	}
	printf("%d", sum);

	

}