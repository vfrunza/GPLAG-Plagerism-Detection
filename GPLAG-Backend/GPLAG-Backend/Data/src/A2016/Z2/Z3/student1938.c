#include <stdio.h>

int main() {
	int n,i,j,c=1;int matrica[20][20]={0};
	while(1)
	{
		printf("Unesite broj tacaka: ");
		scanf("%i",&n);
		if(n<1 || n>10){printf("Pogresan unos\n");}
		else break;
	}
	while(n--)
	{
		do{
		printf("Unesite %i. tacku: ",c);
		scanf("%i %i",&i,&j);
		if(j<0 || j>19 || i<0 || i>19){printf("Pogresan unos\n");}
		}
		while(j<0 || j>19 || i<0 || i>19);
		matrica[j][i]=1;
		c++;
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(matrica[i][j]==1)printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
