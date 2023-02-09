#include <stdio.h>
int main(void) {
	int n, check, max = 0, maxnum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &check);
		if (check > max) {
			max = check;
			maxnum = i+1;
		}
		
	}
	printf("%d\n%d", max, maxnum);
}