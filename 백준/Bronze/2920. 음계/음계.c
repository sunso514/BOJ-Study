#include <stdio.h>
#include <string.h>

int main(void) {
    int num[9];
    scanf("%d %d %d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7]);
    if (num[0] + 1 == num[1]) {
        for (int i = 0; i < 7; i++) {
            if (num[i] + 1 != num[i + 1]) {
                printf("mixed");
                break;
            }
            else {
                if (i == 6) {
                    printf("ascending");
                }
            }
        }
    }
    else if (num[0] - 1 == num[1]) {
        for (int i = 0; i < 7; i++) {
            if (num[i] - 1 != num[i + 1]) {
                printf("mixed");
                break;
            }
            else {
                if (i == 6) {
                    printf("descending");
                }
            }
        }
    }
    else {
        printf("mixed");
    }

    
}