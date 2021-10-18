#include <stdio.h>

int main() {
	int i,j,n=0,x[10]={0},y[10]={0},k;
	char praznamjesta[20][20];
	ponovi1:
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n>10 || n<=0)
	{
		printf("Pogresan unos\n");
		goto ponovi1;
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			praznamjesta[i][j]=' ';
		}
	}
	for(i=0;i<n;i++)
	{
		ponovi2:
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&x[i],&y[i]);
		if((x[i]>=20 || x[i]<0) || (y[i]>=20 || y[i]<0))
		{
			printf("Pogresan unos\n");
			goto ponovi2;
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<20;i++)
		{
			for(j=0;j<20;j++)
			{
				if(i==y[k] && j==x[k])
				{
					praznamjesta[i][j]='*';
				}
				
			}
		}
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%c",praznamjesta[i][j]);
		}
		printf("\n");
	}
	return 0;
}
