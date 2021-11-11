#include <stdio.h>

int main() 
{
	int n, i, j;
	do
	{
		printf ("Unesite broj n: ");
		scanf ("%i", &n);
		if (n<=0 || n>50 ) printf ("Pogresan unos\n");
	} while (n<=0 || n>50);
	 if ( n==1 ) printf("**");
	for (i=0; i<n; i++)
	{
		for (j=0; j<4*n; j++)
		{ 
			if (i==j || i+j==2*n-2 || j-i==2*n-2 || i+j==4*n-4) printf ("*");
			else printf (" ");
		}
		printf ("\n");

	}
	return 0;
}
