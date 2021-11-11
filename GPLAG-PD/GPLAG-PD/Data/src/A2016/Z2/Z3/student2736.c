#include <stdio.h>
#define brelx 10
#define brely 10

int main() 
{
	int n,i,j,t,x[brelx],y[brely];
	
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	while(n<=0 || n>10)
	{
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	}
	
	i=0;
	while(i<n)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19)
		{
			printf("Pogresan unos\n");
			i--;
		}
		i++;
	}
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			for(t=0;t<n;t++)
			{
				if(x[t]==j && y[t]==i)
				{
					printf("*");
					break;
				}
			}
			if(n==t)
				printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
