#include <stdio.h>

int main() {
	
	int n, i, j;
	
	for(;;) {
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n==1) {
		printf("***");
		return 0;
	}
	else if(n>0 && n<=50) {
		for(i=0; i<n; i++) {
			for(j=0; j<(4*n-3); j++) {
				if(i==j || i==j-(2*n-2) || i+j==n-1+(n-1) || i+j==n-1+3*(n-1)) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
		return 0;
	}
	printf("Pogresan unos\n");
	}
	return 0;
}
