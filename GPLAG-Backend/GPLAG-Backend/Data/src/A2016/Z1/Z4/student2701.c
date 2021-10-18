#include <stdio.h>

int main ()
{
	int i, j, n, k, brojac=0, p, s;
	printf("Unesite broj n: ");
	do
	{
		scanf("%d", &n);
		brojac++;
	
	} while(n<1 || n>50);
	p=brojac;
	for(s=1; s<p; s++)
	{
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
	}
	
	if(n!=1)
	{
	k=(4*n-3);
	for(i=0; i<n; i++)
	{
		for(j=0; j<k; j++)
		{
			if(   (i==0 && j==((k-1)/2))  ||   (i==0 && j==0)   ||   (i==0 && j==(k-1))    ) /*1.red*/
			printf("*");
			else if((i+j)==((2*n)-2))
			printf("*");
			else if((j-i)==((2*n)-2))
			printf("*");
			else if(j==i && (j>0 && j<n))
			printf("*");
			else if( ((i+j)==(4*n-4)) && (j>(2*n-2) && j<(k-1)) )
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}
	}
	else
	{
		k=3*n;
		for(i=0; i<k; i++)
		printf("*");
	}
	return 0;
	
}