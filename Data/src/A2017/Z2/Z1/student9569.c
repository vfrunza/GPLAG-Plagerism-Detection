#include <stdio.h>

int main ()
{
	int i,j,n,pola;
	
	do
	{
		printf ("\nUnesite broj N: ");
		scanf ("%d",&n);
		if (n%4!=0 || n<8)
		{
			printf ("Neispravno N!");
		}
		
	} while (n%4!=0 || n<8);
	
	pola=n/2;
	
	
	printf ("\n");
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			/*prvi kvadrant*/
			if (i==j && i<pola && j<pola)
			{
				printf ("\\");
			}
			else if (i<pola && j<pola && i==pola-j-1)
			{
				printf ("/");
				
			}
			/*drugi kvadrant*/
			else if (((j>pola-1) && (i<pola) && (i==0 && j==pola)) || (j==n-1 && i==0) || (i==pola-1 && j==pola) || (i==pola-1 && j==n-1))
			{
				printf ("+");
			}
			else if ((j>pola && j<n-1 && (i==0 || i==pola-1)))
			{
				printf ("-");
			}
			else if ((j==pola || j==n-1) && i>0 && i<pola-1)
			{
				printf ("|");
			}
			/*treci kvadrant*/
			else if ((i==pola || i==n-1) && (j==0 || j==pola-1))
			{
				printf ("+");
			}
			else if ((i==pola || i==n-1) && (j>0 && j<pola-1))
			{
				printf ("-");
			}
			else if ((j==0 || j==pola-1) && (i>pola && i<n-1))
			{
				printf ("|");
			}
			/*cetvrti kvadrant*/
			else if ((i==pola+n/4 && j==pola+n/4) || (i==pola+n/4-1 && j==pola+n/4-1))
			{
				printf ("+");
			}
			else if ((i==pola+n/4 && j==pola+n/4-1) || (i==pola+n/4-1 && j==pola+n/4))
			{
				printf ("+");
			}
			else if ((i==pola+n/4 || i==pola+n/4-1) && i>pola-1 && j>pola-1)
			{
				printf ("-");
			}
			else if ((j==pola+n/4 || j==pola+n/4-1) && i>pola-1 && j>pola-1)
			{
				printf ("|");
			}
			else 
			{
				printf (" ");
			}
		}
		printf ("\n");
	}
	return 0;
}
