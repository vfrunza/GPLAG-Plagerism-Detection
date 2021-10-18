#include <stdio.h>

int main() 
{
	int r,k,s;
	
	do
	{
		printf("Unesite broj redova: ");
		scanf("%d",&r);
	}while(r<=0 || r>10);
	
	do
	{
		printf("Unesite broj kolona: ");
		scanf("%d",&k);
	}while(k<=0 || k>10);
	
	do
	{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&s);
	}while(s<=0 || s>10);
	
	
	int n=(r*2)+1,m=s*k+1+k;
	int i,j;
	
	for(i=0;i<n;i++)
	{
		if(i%2==0) 
		{
			printf("+");
			for(j=0;j<m;j++)
			{
				if(j%(s+1)!=0) printf("-");
				else if(j!=0) printf("+");
			}
		}
		else 
		{
			printf("|");
			for(j=0;j<m;j++)
			{
				if(j%(s+1)!=0) printf(" ");
				else if(j!=0) printf("|");
			}
		}
		printf("\n");
	}
	
	return 0;
}