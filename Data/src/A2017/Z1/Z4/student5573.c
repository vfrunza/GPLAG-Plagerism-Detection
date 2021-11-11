#include <stdio.h>

int main() {
	int red,kolona,s_kolona,i,j,brojac=0;
	do
	{
		printf("Unesite broj redova: ");
		scanf("%d",&red);
	}while(red<=0 || red>10);
	do
	{
		printf("Unesite broj kolona: ");
		scanf("%d",&kolona);
	}while(kolona<=0 || kolona>10);
	do
	{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&s_kolona);
	}while(s_kolona<=0 || s_kolona>10);
	for(i=0;i<(red*2)+1;i++)
	{
		brojac=0;
		if(i%2==0)
		{
			for(j=0;j<(s_kolona*kolona)+kolona+1;j++)
			{
				if(j==(s_kolona+1)*brojac)
				{
					printf("+");
					brojac++;
				}
				else
				{
					printf("-");
				}
			}
		}
		else
		{
			for(j=0;j<(s_kolona*kolona)+kolona+1;j++)
			{
				if(j==(s_kolona+1)*brojac)
				{
					printf("|");
					brojac++;
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
