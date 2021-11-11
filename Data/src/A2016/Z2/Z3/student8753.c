#include <stdio.h>

int main() {
	int mat[20][20];
	int m;
	int s;
	for(m=0;m<20;m++)
	{ 
		for (s=0;s<20;s++) 
     {
		mat[m][s]=0;
    	}
	}
	
	int tacka;
	int prvatacka;
	int drugatacka;
	
	printf("Unesite broj tacaka: ");
	scanf("%d", &tacka);
	while(tacka<=0 || tacka>10) 
	{
		
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d", &tacka);
	}

	for(m=0; m<tacka; m++) 
	{
		printf("Unesite %d. tacku: ", m+1);
		scanf("%d %d", &prvatacka,&drugatacka); 
		while(prvatacka<0 || drugatacka<0|| prvatacka>19 || drugatacka>19) 
		{ 
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",m+1);
			scanf("%d %d", &prvatacka,&drugatacka);
	}
		
		mat[prvatacka][drugatacka]=1; }
		
		for(m=0; m<20; m++) 
		{
			for(s=0;s<20;s++) {
				if(mat[s][m]==1) {
					printf("*");
				
				}
				else printf(" ");
			}
			printf("\n");
		}
		
	
	return 0;
}
