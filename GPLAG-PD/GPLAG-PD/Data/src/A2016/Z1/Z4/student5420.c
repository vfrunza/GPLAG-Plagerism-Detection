#include <stdio.h>

int main() {
	int i,j,n;
	for(;;) { 
		printf("Unesite broj n: ");
	    scanf("%d", &n);
	    if(n<=50 && n>0) break;
	    printf("Pogresan unos\n");
	}
	if(n==1) {
		printf("***");
		return 0;
	}
	for(i=0; i<n; i++) {
		for(j=0; j<4*n-3; j++) {
			if((i==j || i==j-2*n+2)||((i+j==2*n-2)||(i+j==4*n-4))) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
