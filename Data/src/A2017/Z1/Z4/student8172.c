#include <stdio.h>

int main() {
	int red,kol,skol,i,j,k;
	
	//unos redova (od 1 do 10)
	do 
	{
		
		printf ("Unesite broj redova: ");
		scanf("%d",&red);
	}
	while((red<1)|| (red>10));
	//Unos kolona  (od 1 do 10)
	do
	{
		printf("Unesite broj kolona: ");
		scanf("%d",&kol);
		}
		while ((kol<1) || (kol>10));
		
		//Unos sirine kolone (od 1 do 10)
		do
		{
			printf("Unesite sirinu jedne kolone: ");
			scanf("%d",&skol);
		}
		while ((skol<1) || (skol>10));
		
		//Ponavljanje prvog reda (bez zadnje linije)
		for (j = 0; j < red; j++) {
			
			//+---+---
			
			for(i = 0; i < kol; i++); {
				printf("+");
				for(k = 0; k < skol; k++) {
					printf("-");
				}
				
			}
			//Zadnji+
			printf("+");
			printf("\n");
			
			//Vertikalne linije |
			for(i = 0;i < kol;i++) {
				printf("|");
				for(k = 0;k < kol;k++) {
					printf(" ");
				}
			}
			//Zadnja linija |
			printf("|");
			printf("\n");
			
		}
		//+---+--- zadnja linija
		for(i = 0;i < kol;i++);
		{
			printf("+");
			for (k = 0; k < skol; k++) {
				printf("-");
			}
			for (i=0; i<red; i++) {
				for (j=0; j<kol; j++) {
					if(j==0) printf("+");
					for(k=0; k<skol; k++) {
						printf("-");
					
					}
				}
					printf("+");
					printf("\n");
				}
			}
		{	printf(" ");
			
		}
		{ printf("|");
		}
		{ if (i==red - 1)
		for (i=0; i<red; i++)
		{
			for (j=0; j<kol; j++)
	    {
	    	if(j==0) printf("+");
	    	for(k=0; k<skol; k++);
	    {
	    printf("-");
		}
		printf("+");
		printf("\n");
	    }
		}
		}
		
		
		//Zadnji +
		printf("+");
		
		return 0; 
}