#include <stdio.h>

int main() {
	int broj_redova, broj_kolona, sirina_jedne_kolone, i, j, n;
	do{
	printf("Unesite broj redova: ");
	scanf("%d", &broj_redova);
	}
	while(broj_redova<=0 || broj_redova>10);
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &broj_kolona);
	}
	while (broj_kolona<=0 || broj_kolona>10);
		
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina_jedne_kolone);
}
	while (sirina_jedne_kolone<=0 || sirina_jedne_kolone>10);
	
	for (n = 0; n <broj_redova; n++) {
		
		
		/* prvi red*/
	for (j = 0; j < broj_kolona; j++) {
		printf("+");
	
	for (i = 0; i <sirina_jedne_kolone; i++) {
		printf("-");
		}
	}
		printf("+");
		printf("\n");
		
	/*sl red*/
	for (j = 0; j < broj_kolona; j++) {
		printf("|");
	
	for (i = 0; i <sirina_jedne_kolone; i++) {
		printf(" ");
		}
	}
		printf("|");
		printf("\n");
		}
		/*posljednja li*/
	for (j = 0; j < broj_kolona; j++) {
		printf("+");
	
	for (i = 0; i <sirina_jedne_kolone; i++) {
		printf("-");
		}
	}
		printf("+");
		printf("\n");
	
	
	return 0;
}
