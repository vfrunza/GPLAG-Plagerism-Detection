#include <stdio.h>

int main() {
	int broj_redova,broj_kolona,sirina_kolona,i,j,k,l;
		do{
			printf("Unesite broj redova: ");
			scanf("%d",&broj_redova);
			
			}while(broj_redova<=0 || broj_redova>10);
		
		
		do{
			printf("Unesite broj kolona: ");
			scanf("%d",&broj_kolona);
			
			}while(broj_kolona<=0 || broj_kolona>10);
		
	
		do{
			printf("Unesite sirinu jedne kolone: ");
			scanf("%d",&sirina_kolona);
		
			}while(sirina_kolona<=0 || sirina_kolona>10);

		
		for(i = 0; i < broj_redova; i++)
		{
			for(j = 0 ; j < broj_kolona; j++)
			{
				printf("+");
				for(k = 0; k < sirina_kolona; k++)
				{
					printf("-");
				}
			}
			printf("+\n");
			for(j= 0; j < broj_kolona; j++)
			{	
				printf("|");
				for(l= 0; l < sirina_kolona; l++)
				{
					printf(" ");
				}
			}
				printf("|\n");
	
		}
		for(j = 0; j < broj_kolona; j++)
		{
			printf("+");
			for(k = 0; k < sirina_kolona; k++)
			{
				printf("-");
			}
		}
		printf("+");
	
	return 0;
}
