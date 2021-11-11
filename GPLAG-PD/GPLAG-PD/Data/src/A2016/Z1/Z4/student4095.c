#include <stdio.h>

int main() {
	int n, i, j, k, l, m;
	do
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if (n<=0 || n>50)
		{
			printf("Pogresan unos\n");
		}
	} while (n<=0 || n>50);
	
if (n!=1)
{
	for (i=1; i<=n; i++)
	{
		for (j=2; j<=i; j++)  
		{
			printf(" ");
		}
		printf("*");          
		
		for (k=1; k<=(2*(n-i)-1); k++)       
		{
			printf(" ");
		}
		
		if (i>1 && i<n) 
		{
			printf("*");         
		}
		
		for (l=0; l<2*i-3; l++)
		{
			printf(" ");
		}
		
			printf("*");
		
		for (m=1; m<=(2*(n-i)-1); m++)     
		{
			printf(" ");
		}
		
		if (i<n)
		{
			printf("*");
		}
		
		printf("\n");
	}
}
else 
{
	printf("***");
	
}
	return 0;
}
