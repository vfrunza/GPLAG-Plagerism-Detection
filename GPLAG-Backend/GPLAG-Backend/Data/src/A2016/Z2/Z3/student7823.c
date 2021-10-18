#include <stdio.h>

int main()
{
//	printf("Zadaća 2, Zadatak 3");
	int i,j,k,broj, vrijednostA[10],  vrijednostB[10];
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj);
		if(broj<=0 || broj>10)
			printf("Pogresan unos\n");
	} while(broj<=0 || broj>10);
	for(i=0; i<broj; i++) {
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &vrijednostA[i], &vrijednostB[i]);
		if(vrijednostA[i]>19 || vrijednostA[i]<0 || vrijednostB[i]>19 || vrijednostB[i]<0) {
			i--;
			printf("Pogresan unos\n");
			continue;
		}
	}
	for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			for(k=0; k<broj; k++) {
				if(vrijednostA[k]==j && vrijednostB[k]==i) {
					printf("*");
					j++;
				}
			}
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
