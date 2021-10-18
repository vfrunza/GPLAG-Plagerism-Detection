#include <stdio.h>

+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+

int main() {
	printf("Zadaća 1, Zadatak 4");
	return 0;
}

#include <stdio.h>

int main() {
	int r,k,sk,i,j,l;
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
		scanf("%d",&sk);
		
	}while(sk<=0 || sk>10);
	
	for(i=0;i<k;i++)
	{	
		printf("+");
		for(j=0;j<sk;j++)
		{
			printf("-");
		}
		if (i==k-1)
			printf("+");
	}
	printf("\n");
		
	for(l=0;l<r;l++)
	{
		for(i=0;i<k;i++)
		{
			printf("|");
			for(j=0;j<sk;j++)
			{
				printf(" ");
			}
			if (i==k-1)
				printf("|");
		}
		printf("\n");
		for(i=0;i<k;i++)
		{
			printf("+");
			for(j=0;j<sk;j++)
			{
				printf("-");
			}	
			if (i==k-1)
				printf("+");
		}
		printf("\n");
	}	
	
	return 0;
}