#include <stdio.h>

int main() 
{
	int i,j,k,m,o,n;
	naredba: printf ("Unesite broj n: ");
	scanf ("%i",&n);
	if (n>50  || n<1 )
	{
	    printf ("Pogresan unos\n");
	    goto naredba;
	}
	else if (n==1)
	{
		printf ("***");
	}
	
	else
	{
/***************************************************************************************/
		for (i=0;i<=n;i++)
		{
			if (n==1)
			{
				printf ("*");
			}
			for (j=0;j<n;j++)
			{
				if (j==i)
				{
					printf ("*");
				}
				else 
				{
					printf (" ");
				}
			}
			for (k=0;k<n-2;k++)
			{
				if (i+k==n-2)
				{
					printf ("*");
				}
				else 
				{
					printf (" ");
				}
			}
			for (m=0;m<n;m++)
			{
				if (i==m)
				{
					printf ("*");	
					
				}
				else 
				{
					printf (" ");
				}
			}
			for (o=0;o<n;o++)
			{
				if (o+i==n-2)
				{
					printf ("*");
				}
				else 
				{
					printf (" ");
				}
			}
			
			printf ("\n");
		}
/**************************************************************************************/
	}	


	

	return 0;
}