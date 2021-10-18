#include <stdio.h>

int main() {
int n,i,j;
A:
printf("\nUnesite broj n: ");
scanf("%d", &n);
if(n<=0 || n>50) {
    printf("Pogresan unos");
    goto A;
}
if(n==1) {
    printf("***");
    return 0;
    }
for(i=0;i<n;i++){
    for(j=0;j<4*n-3;j++) {
        if(i==j || i==j-2*(n-1) || i+j==n-1+3*(n-1) || i+j==2*(n-1)){
            printf("*");
          
        }
        else printf(" ");
    }
        printf("\n");
}

	return 0;
}
