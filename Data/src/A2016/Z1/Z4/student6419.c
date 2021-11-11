#include <stdio.h>
int main () {
	int n, i, j;
	do {
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50)
		printf("Pogresan unos\n");
	}while(n<=0 || n>50);
	
	for(i=0; i<n; i++) {
		for(j=0; j<4*n; j++) {
			if(i==j && i<=n || i+j==2*n-2 || i+j==4*n-4 || j-i==2*n-2)
				printf("*");
			else if(n==1 && j<4*n-1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}