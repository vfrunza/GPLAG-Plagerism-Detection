#include <stdio.h>

int main() {
	int broj_redova, broj_kolona, sirina_kolone,i,j;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&broj_redova);
	}while(broj_redova<=0||broj_redova>10);
	
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&broj_kolona);
	}while(broj_kolona<=0||broj_kolona>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina_kolone);
	}while(sirina_kolone<=0||sirina_kolone>10);
	
	for ( i = 1; i <=2*broj_redova+1 ; i++) {
		for ( j = 1; j <=broj_kolona+1+broj_kolona*sirina_kolone ; j++) {
			if(i%2==1&&j%(sirina_kolone+1)==1){
				printf("+");
			}
			else if(i%2==1){
				printf("-");
			}
			else if(i%2==0&&j%(sirina_kolone+1)==1){
				printf("|");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	

	return 0;
}
