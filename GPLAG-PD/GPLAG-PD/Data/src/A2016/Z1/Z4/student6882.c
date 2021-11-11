#include <stdio.h>

int main()
{
	int n=0;
	while (n<=0 || n>50)
	{
		printf ("Unesite broj n: ");
		scanf ("%d",&n);
		if (n<=0 || n>50) printf ("Pogresan unos\n");
		
	}
	
	int m=n+3*(n-1);
	if (n==1)
	{
		printf ("***");
		return 0;
	}
	int i,j;
	for (i=0; i<n;i++)
	{
		for (j=0;j<m;j++){
			if (i==j || i+n+(n-2)==j || n+(n-2)-i==j || 2*(n+(n-2))-i==j)
			printf ("*");
			else
			printf (" ");
			
			
		}
		printf ("\n");
	}
return 0;
}