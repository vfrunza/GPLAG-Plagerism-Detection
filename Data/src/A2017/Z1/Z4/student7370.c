#include <stdio.h>

int main() {
	int m, n, b, i, j, c;
	i=0; j=0; c=0;
	do
	{
		printf("Unesite broj redova: ");
		scanf("%d", &m);
	}while(m<=0 || m>10);
	
	do
	{
		printf("Unesite broj kolona: ");
	scanf("%d", &n);
	}while(n<=0 || n>10);
	
	do
	{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &b);
	}while(b<=0 || b>10);

	do
	{
		do
		{
			c=0;
			printf("+");
			do
			{
				printf("-");
				c++;
			}while(c<b);
			if(j==n-1) printf("+\n");
			j++;
		}while(j<n);
		
		j=0;
		
		do
		{
			c=0;
			printf("|");
			do
			{
				printf(" ");
				c++;
			}while(c<b);
			if(j==n-1)
			printf("|\n");
			j++;
		}while(j<n);
		j=0;
		i++;
	}while(i<m);
	
	do
	{
		c=0;
		printf("+");
		do
		{
			printf("-");
			c++;
		}while(c<b);
		if(j==n-1) printf("+");
		j++;
	}while(j<n);
	
	return 0;
}
