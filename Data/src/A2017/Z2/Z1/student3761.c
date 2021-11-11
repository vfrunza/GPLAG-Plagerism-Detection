#include <stdio.h>

int main ()
{
	int n, i, j;
	printf ("Unesite broj N: ");
	do 
	{
		scanf ("%d", &n);
	}
	while (n%4!=0);
	printf ("\n");
	for (i=0; i<n/2; i++)
	{
		for (j=0; j<n; j++)
		{
			if (j<n/2)
			{
				if (i==j)
					printf ("\\");
				else if (i+j==n/2-1)
					printf ("/");
				else
					printf (" ");
			}
			if (j>=n/2 && j<n)
			{
				if (i==0 || i==n/2-1)
				{
					printf ("+");
					for (j=n/2+1; j<=n-2; j++)
						printf ("-");
					printf ("+");
				}
				else
				{
					printf ("|");
					for (j=n/2+1; j<=n-2; j++)
						printf (" ");
					printf ("|");
				}
			}
		}
		printf ("\n");
	}
	
	for (i=n/2; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (j<n/2)
			{
				if (i==n/2 || i==n-1)
				{
					printf ("+");
					for (j=n/2+1; j<=n-2; j++)
						printf ("-");
					printf ("+");
				}
				else
				{
					printf ("|");
					for (j=n/2+1; j<=n-2; j++)
						printf (" ");
					printf ("|");
				}
			}
			if (j>=n/2 && j<n)
			{				
				if (i==3*n/4 || i==3*n/4-1)             
				{
					for (j=n/2; j<=n-2; j++)
						printf ("-");
				}
				else if (j==3*n/4 || j==3*n/4-1)
					printf ("|");
				else 
					printf (" ");
			}
		}
		printf ("\n");
	}
	return 0;
}