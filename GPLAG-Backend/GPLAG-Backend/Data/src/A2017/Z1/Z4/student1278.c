#include <stdio.h>

int main() {
	int m, n, p, i, j, k;
	
	do
	{
		printf("Unesite broj redova: ");
		scanf ("%d", &n);
	}while(n<=0 || n>10);
	
	do
	{
		printf("Unesite broj kolona: ");
		scanf("%d", &m);
	}while (m<=0 || m>10); 
	
	do
	{
		printf("Unesite sirinu jedne kolone: ");
		scanf ("%d", &p);
	}while (p<=0 || p>10);
		
		
	for (i=0; i<(2*n+1) ; i++)
	{
		for(j=0; j<(m+p*m+1); j++)
		{
			
			if(i%2==0 && j%(p+1)==0 )
			printf("+");
			else if( i%2==0 && j%(p+1)!=0 )
			printf("-");
			else if(i%2==1 && j%(p+1)==0 )
			printf("|");
			else if(i%2==1 && j%(p+1)!=0)
			printf(" ");
			
			
		}
		printf("\n");
		
	}
	
	return 0;
}








			
	