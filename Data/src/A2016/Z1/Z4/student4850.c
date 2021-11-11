#include <stdio.h>

int main() {
	int i, j, n;
	
	labela:
	printf("\nUnesite broj n: ");
	scanf("%d", &n);
	
	if(n<=0 || n>50) {
		printf("Pogresan unos ");
		goto labela;
	}
	
	for(i=0; i<n; i++) {
		for(j=0; j<=(4*n-4); j++) {
			if(n==1) {
				printf("***");
			} else if(i==j) {
				printf("*");
			} else if(j==2*n-2-i) {
				printf("*");
			} else if(j==4*n-4-i) {
				printf("*");
			} else if(j==2*n-2+i) {
				printf("*");
			} else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
