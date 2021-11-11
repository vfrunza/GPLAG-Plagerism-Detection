#include <stdio.h>

int main() 
{
	int n, i ,j;
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	for(i=0; i<9999; i++)
	{
	if(n<=0 || n>50)
	{
		printf("Pogresan unos");
		printf("\nUnesite broj n: ");
		scanf("%d", &n);
		continue;
	}
	else break;
	}
	
	if(n==1)
	printf("***");
	
	else
	{
	for(i=0; i<n; i++)
	{
		for(j=0; j<=(4*n-4); j++)
		{
			if((i+j)==(2*n-2) || i==j || (j-i)==(2*n-2) || (i+j)==(n*4-4))
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}
	}
	
	return 0;
}
