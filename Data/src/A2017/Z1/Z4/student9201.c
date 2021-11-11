#include <stdio.h>

int main() {
	
	int redovi = 0;
	int kolone = 0;
	int sirina = 0;
	
	do
	{
		printf("Unesite broj redova: ");
		scanf("%d", &redovi);
	} while (redovi<=0 || redovi>10);
	
	do
	{
		printf("Unesite broj kolona: ");
		scanf("%d", &kolone);
	} while (kolone<=0 || kolone>10);
	
	do
	{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina);
	} while (sirina<=0 || sirina>10);
	
	
	int i, j, k;
	
	for (i = 0; i <redovi; i++)
		{
			for (j = 0; j<kolone; j++)
				{
					printf("+");
					for (k = 0; k<sirina;k++)
						printf("-");
						
				}
				
			printf("+\n");
			
			for (j = 0; j<kolone; j++)
				{
					printf("|");
					for (k = 0; k<sirina;k++)
						printf(" ");
						
				}
				
			printf("|\n");
		}
	
	for (j = 0; j<kolone; j++)
				{
					printf("+");
					for (k = 0; k<sirina;k++)
						printf("-");
						
				}
				
	printf("+\n");
	
	
	
	
	
	return 0;
}
