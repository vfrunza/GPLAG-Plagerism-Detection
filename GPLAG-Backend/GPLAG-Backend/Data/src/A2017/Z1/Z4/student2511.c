#include <stdio.h>
#include <math.h>
int main()
{
	int kolone,redovi,sirina,i,j,k;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&redovi);
	}while(redovi>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&kolone);
	}while(kolone>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina);
	}while(sirina>10);
	for(i=0;i<redovi;i++)
	{
		for(j=0;j<kolone;j++)
		{
	
			printf("+");
		
			
			for(k=0;k<sirina;k++)
			{
				printf("-");
				}
			}
		printf("+\n");
	
	
	for(j=0;j<kolone;j++)
		{
	
			printf("|");
			
			for(k=0;k<sirina;k++)
			{
				printf(" ");
				}
		}
				printf("|\n");
					
	
	}
		for(i=0;i<sirina-redovi;i++)
	{
		for(j=0;j<kolone;j++)
		{
	
			printf("+");
		
			
			for(k=0;k<sirina;k++)
			{
				printf("-");
				}
			}
		printf("+\n");
	}

	
			
		
		
		

		
	
	return 0;
}
