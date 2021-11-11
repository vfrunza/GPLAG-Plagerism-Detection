#include <stdio.h>

int main() {
	int i, j;
	int n;
	pocetak:
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<=0 || n>50) {
		printf("Pogresan unos\n");
		goto pocetak;
	}
	if(n==1) {
		printf("**");
	}
	for(i=1; i<=n; i++) {
		for(j=1; j<=4*n-1; j++) {
			if(i==j || j+i==2*n || j-i==2*n-2 || i+j==4*n-2) {
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
