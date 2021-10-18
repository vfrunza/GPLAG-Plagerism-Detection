#include <stdio.h>

int main() {
	
	int n=0, i, j;
	
	for (;;) {
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if (n>0 && n<=50) break;
		else {
			printf("Pogresan unos\n");
			continue;
		}
	}
	
	if (n==1) {
		printf("***");
	} else {
			for (i=1; i<=n; i++) {
				for (j=1; j<=n+3*(n-1); j++) {
					if (i==j || i==j-2*n+2 || i+j==2*n || i+j==n+3*(n-1)+1) printf("*");
					else printf(" ");
				}
			printf("\n");
			}
	}
	
	return 0;
}
