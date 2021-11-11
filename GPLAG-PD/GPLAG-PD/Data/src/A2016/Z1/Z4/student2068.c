#include <stdio.h>

int main() {
	int n, i, j;
	do {
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<1||n>50) {
			printf("Pogresan unos\n");
		}
	}
	while(n<1||n>50);
	/* Specijalni slucaj za n=1 */
	if(n==1) {
		printf("***");
	}
	else {
	for(i=1; i<=n; i++) {
		
		/* Broj praznih mjesta na pocetku */
		for(j=1; j<i; j++) {
			printf(" ");
		}
		
		/* Prva zvjezdica */
		printf("*");
		
		/* Broj praznih mjesta izmedju prve i druge */
		for(j=1; j<=(2*n-2*i-1); j++) {
			printf(" ");
		}
		
		/* Druga zvjezdica */
		if(j!=1) {
			printf("*");
		}
		
		
		/* Broj praznih mjesta izmedju sredisnjih zvjezdica */
		for(j=1; j<=(2*i-3); j++) {
			printf(" ");
		}
		
		/* Treca zvjezdica */
		if(j!=1) {
			printf("*");
		}
		
		/* Broj praznih mjesta izmedju trece i cetvrte */
		for(j=1; j<=(2*n-2*i-1); j++) {
			printf(" ");
		}
		
		/*  Cetvrta zvjezdica */
		if(j!=1) {
			printf("*\n");
		}	
	}
	}
	return 0;
}
