#include <stdio.h>

int main()
{
	int red,kolona,sirina_kolone,i,j,k,a,b,c,d ;
	do
		{ printf("Unesite broj redova: ");
		  scanf("%d",&red);
		}
	while(red<=0 || red>10);
	do
		{ printf("Unesite broj kolona: ");
		  scanf("%d",&kolona);
		}
	while(kolona<=0 || kolona>10);
	do
		{ printf("Unesite sirinu jedne kolone: ");
		  scanf("%d",&sirina_kolone);
		}
	while(sirina_kolone<=0 || sirina_kolone>10);
	
	for (i=0;i<red;i++)
		{
		for(j=0;j<kolona;j++)
			{
		for(k=0;k<1;k++)
			{
				printf("+");
			}
		for(a=0;a<sirina_kolone;a++)
			{
				printf("-");
			}}
				printf("+");
				printf("\n");
		for(j=0;j<kolona;j++)
				{
		for(k=0;k<1;k++)
				printf("|");
		for(a=0;a<sirina_kolone;a++)
				printf(" ");
				}	
				printf("|\n");
		}
	for(b=0;b<kolona;b++)
		{
		for(c=0;c<1;c++)
			{	
			printf("+");
			}
		for(d=0;d<sirina_kolone;d++)
			{
			printf("-");
			}
		}
		printf("+");
		return 0;
	}