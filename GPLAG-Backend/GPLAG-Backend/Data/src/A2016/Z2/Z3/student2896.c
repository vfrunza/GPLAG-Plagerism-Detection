#include <stdio.h>

int main() {
	int x[10],y[10],n,i,j,k,br=0;
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n<1 || n>10) printf("Pogresan unos\n");
	} while(n<1 || n>10);
	for(i=0;i<n;i++)
	{
		do
		{
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&x[i],&y[i]);
			if(x[i]<0 || x[i] >19 || y[i] < 0 || y[i] > 19) printf("Pogresan unos\n");
		} while(x[i]<0 || x[i]>19 || y[i]<0 ||y[i]>19);
	}
	for(i=0;i<=19;i++)
	{
		for(j=0;j<=19;j++)
		{
			br=0;
			for(k=0;k<n;k++)
			{
				if(x[k]==j && y[k]==i)
				{
					printf("*");
					br=1;
					break;
				}
			}
			if(br==0) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
