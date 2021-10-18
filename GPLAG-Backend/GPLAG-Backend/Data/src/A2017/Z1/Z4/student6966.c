#include <stdio.h>

int main()
{
	int i,j,k,red,kolona,sirina_kolone;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&red);
	} while(red<=0 || red>10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&kolona);
	} while(kolona<=0 || kolona>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirina_kolone);
	} while(sirina_kolone<=0 || sirina_kolone>10);
	printf("+");
	for(j=0; j<kolona; j++) {
		for(k=0; k<sirina_kolone; k++) {
			printf("-");
		}
		printf("+");
	}
	printf("\n");
	for(i=1; i<=2*red; i++) {
		if(i%2==0) printf("+");
		else printf("|");
		for(j=0; j<kolona; j++) {
			for(k=0; k<sirina_kolone; k++)
				if(i%2==0) printf("-");
				else printf(" ");
			if(i%2==0) printf("+");
			else printf("|");

		}
		printf("\n");
	}
	return 0;
}
