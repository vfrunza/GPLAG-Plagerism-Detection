#include <stdio.h>

int main() {
	int n, i, j;
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	while(n<=0 || n>50) {
		printf("Pogresan unos\nUnesite broj n: ");
		scanf("%d", &n);
	}
	
	if(n==1) {
		printf("***");	/*ispis je jednostavan u ovom slucaju i moze se ispisati na ovaj nacin*/
		return 0;
	}
	
	for(i=0; i<n; i++) {
		for(j=0; j<=(n-1)*4; j++) {
			if(((j+i)%(2*(n-1))==0 || (j-i)%(2*(n-1))==0)) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
