#include <stdio.h>

int main() {
	int red,kolona,sirina,i,j,k;
	do{
		
	printf("Unesite broj redova: ");
	scanf("%d",&red);
		
	}
	while(red<1||red>10);

	do{
		
	printf("Unesite broj kolona: ");
	scanf("%d",&kolona);
		
	}
	while(kolona<1||kolona>10);

	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina);}
	while(sirina<1||sirina>10);
	
	for(i=0;i<red;i++)
	{
		printf("+");
		for(j=0;j<kolona;j++)
		{
			for(k=0;k<sirina;k++)
			{    
				printf("-");
			}
			printf("+");
		}
		printf("\n");
		printf("|");
		for(j=0;j<kolona;j++)
		{
			for(k=0;k<sirina;k++)
			{
				printf(" ");
			}
			printf("|");
		}
		printf("\n");
		
		
	}
	printf("+");
	for(j=0;j<kolona;j++)
	{
		for(k=0;k<sirina;k++)
		{
			printf("-");
		}
		printf("+");
	}
	
	
	
	return 0;
}
