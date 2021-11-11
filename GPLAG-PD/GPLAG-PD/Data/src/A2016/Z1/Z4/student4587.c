#include <stdio.h>

int main() {
    int n, j, k;
    printf("Unesite broj n: ");
    scanf("%d", &n);
    while (n<1 || n>50) {
        printf("Pogresan unos\n");
        printf("Unesite broj n: ");
        scanf("%d", &n);
    }
    if(n==1) {
        printf("**");
    }
    for(j=0; j<=n-1; j++) {
        for(k=0; k<=4*(n-1); k++) {
            if(j==k && k<n-1)
            printf("*");
            else if (j+k==2*(n-1))
            printf("*");
            else if(k-j==2*(n-1))
            printf("*");
            else if (j+k==4*(n-1))
            printf("*");
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    
	return 0;
}
