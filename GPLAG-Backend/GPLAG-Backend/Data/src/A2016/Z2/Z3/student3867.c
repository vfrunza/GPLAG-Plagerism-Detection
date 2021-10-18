#include <stdio.h>

int main() 
	{
		int i=0,j=0,max=0,maxx=0,tac,n,x[20]={0},y[20]={0};
		char zv[20][20]={{0}};
		for(;;)
		{
			printf("Unesite broj tacaka: ");
			scanf("%d",&n);
			if(n<1 || n>10)
			{
				printf("Pogresan unos\n");
				continue;
			}
			else break;
		}
		for(i=0;i<n;i++)
		{
			tac=i+1;
			printf("Unesite %d. tacku: ",tac);
			scanf("%d %d",&x[i],&y[i]);
			if((x[i]<0 || x[i]>19) || (y[i]<0 || y[i]>19))
			{
				printf("Pogresan unos\n");
				i--;
				continue;
			}
			zv[x[i]][y[i]]='*';
			if(y[i]>=max)
				max=y[i];
			if(x[i]>=maxx)
				maxx=x[i];
		}
		for(j=0;j<max+1;j++)
		{
			for(i=0;i<maxx+1;i++)
			{
				if(zv[i][j]=='*')
					printf("%c",zv[i][j]);
				else printf(" ");
			}
			printf("\n");
		}
		return 0;
	}