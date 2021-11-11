#include <stdio.h>

int main() {
	
	int redovi, kolone, sirina, i, j;
	
	do{
    printf("Unesite broj redova: ");
	scanf("%d",&redovi);
	}while(redovi<=0 || redovi>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&kolone);
	}while(kolone<=0 || kolone>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina);
	}while(sirina<=0 || sirina>10);
	
	for(i=0;i<=redovi*2;i++){
		for(j=0;j<=(kolone*sirina)+kolone;j++){
			if(i%2==0 && (j==0 || j%(sirina+1)==0)) printf("+");
			else if(i%2!=0 && (j==0 || j%(sirina+1)==0)) printf("|");
			else if(i%2==0 && j>0) printf("-");
			else printf(" ");
			}
		printf("\n");
	}
	
	return 0;
}
