#include <stdio.h>
int main () {
    int i, j, n;
    do {
        printf("Unesite broj n: ");
        scanf("%d", &n);
        if(n < 1 || n > 50) {
            printf("Pogresan unos\n");
        }
    } while(n < 1 || n > 50);
    printf("*");
    for(i = 2*(n-2) + 1; i > 0; i--) {
        printf(" ");
    }
    printf("*");
    for(i = 2*(n-2) + 1; i > 0; i--) {
        printf(" ");
    }
    printf("*\n");
    for(i=1; i<n-1; i++) {
        for(j=0; j<i; j++) {
            printf(" ");
        }
        printf("*");
        for(j = 2*(n-i-2) + 1; j > 0; j--) {
            printf(" ");
        }
        printf("*");
        for(j = 2*(i-1) + 1; j > 0; j--) {
            printf(" ");
        }
        printf("*");
        for(j = 2*(n-i-2) + 1; j > 0; j--) {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    if(n > 1) {
        for(i=0; i<n-1; i++) {
                printf(" ");
            }
        printf("*");
        for(j = 2*(n-2) + 1; j > 0; j--) {
            printf(" ");
        }
        printf("*");
    }
    return 0;
}
