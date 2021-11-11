#include <stdio.h>

int main() {
	int n, i=1, j=1;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while (n<=0 || n>50) {printf("Pogresan unos\n"); printf("Unesite broj n: "); scanf("%d", &n);}
	if (n==1) {printf("**");}
	for (i=1; i<=n; i=i+1) {
		for (j=1; j<=4*n-3; j=j+1) {
			if (j==i || ((double)(j+i)/2.0)==(double)n || ((double)(j-i)/2==(double)(n-1)) || ((double)(i+j)/2==(double)(n+n-1))) {printf("*");} else {printf(" ");
		
		}
		}
		printf("\n");
	}
	return 0;
}
