#include <stdio.h>

int main() 
{
	int n, k=0;
	printf ("Unesite broj n: ");
	scanf ("%d", &n);
	

	if (n>k || n<=0 || n>50)
	{
	while (n<=0 || n>50)
	{
		printf ("Pogresan unos\n");
		printf ("Unesite broj n: ");
		scanf ("%d",&n);
		if (n==k && n>0 &&n<51)
		break;
	}
	}
	
	
	if (n==1)
	{
		printf ("***");
		return 0;
	}
	

	int i,j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<=4*n-4; j++)
		{
			if (i==j || i+j==2*n-2 || j-i==2*n-2 || i+j==4*n-4)
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
	
	
	return 0;
}
