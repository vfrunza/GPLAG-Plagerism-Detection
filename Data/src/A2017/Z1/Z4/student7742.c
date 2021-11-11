#include <stdio.h>

int main()
{
int broj_redova,broj_kolona,sirina,i,j,k;
do{
printf("Unesite broj redova: ");
scanf("%d", &broj_redova);
}while(broj_redova<0 || broj_redova>=10);
do{
printf("Unesite broj kolona: ");
scanf("%d", &broj_kolona);
}while(broj_kolona<0||broj_kolona>=10);
do{
printf("Unesite sirinu jedne kolone: ");
scanf("%d", &sirina);
}while(sirina<0 || sirina>=10);

for(i=0; i<broj_redova; i++) {
	for(j=0; j<broj_kolona; j++) {
		if(i==0 && j==0) {
			printf("+");
		}else if(j==sirina) {
			printf("+");
		}else{
			printf("-");
		}
	}
	
}
	return 0;
}

/*
	int broj_redova, broj_kolona, sirina_kolone;
do{
	printf("Unesite broj redova: ");
	scanf("%d", &broj_redova);
} while (broj_redova<=0 || broj_redova>10);
do{
	printf("Unesite broj kolona: ");
	scanf("%d", &broj_kolona);
} while(broj_kolona<=0 || broj_kolona>10);
do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina_kolone);
}while(sirina_kolone<=0 || sirina_kolone>10);

	int i,j,k,l;
	for(k=0; k<broj_redova; k++) {
		for(i=0; i<broj_kolona; i++) {
			printf("+");
			for(j=0; j<sirina_kolone; j++) {
				printf("-");

			}
		}
		printf("+\n");
		for(l=0; l<broj_kolona; l++) {
			printf("|");

			for(j=0; j<sirina_kolone; j++) {
				printf(" ");
			}
		}
		printf("|\n");
	}
	for(i=0; i<broj_kolona; i++) {
		printf("+");
		for(j=0; j<sirina_kolone; j++)
		{
			printf("-");

		}
	}
	printf("+");
	*/