#include <stdio.h>

int main()
{
	int redovi;
	int kolone;
	int sirina;

	do {
		printf("Unesite broj redova: ");
		scanf("%d", &redovi);
	} while(redovi<1 || redovi>10);

	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &kolone);
	} while(kolone<1 || kolone>10);

	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
	} while(sirina<1 || sirina>10);

	int i;
	int j;
	int k;

	for(i=0; i<redovi; i++) {
		for(j=0; j<kolone; j++) {
			printf("+");
			for(k=0; k<sirina; k++) {
				printf("-");
			}
		}
		

		printf("+\n");

		for(j=0; j<kolone; j++) {
			printf("|");
			for(k=0; k<sirina; k++) {
				printf(" ");
			}
		}

		printf("|\n");
	}

	for(j=0; j<kolone; j++) {
		printf("+");
		for(k=0; k<sirina; k++) {
			printf("-");
		}
	}
	printf("+\n");

	return 0;
}
