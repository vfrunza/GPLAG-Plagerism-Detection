#include <stdio.h>

int main() 
{
	int j, n, i;
	int p, d, m[20][20] = {{0}};
	
	do 
	{
		printf ("Unesite broj tacaka: ");
		scanf ("%d.", &n);
		
		if (n<1 || n>10) 
		{
			printf ("Pogresan unos\n");
		}
		
	} while (n<1 || n>10);
	
		for (i=1; i<=n; i++) 
		{
		    printf ("Unesite %d. tacku: ", i);
			scanf ("%d %d", &d, &p);
		
		while ((d<0 || d>19) || (p<0 || p>19)) 
		{
			printf ("Pogresan unos\n");
		    printf ("Unesite %d. tacku: ", i);
		    scanf ("%d %d", &d, &p);
		}
		m[p][d] = 1;
	}
	
	while (i<n);
	
	for (i=0; i<20; i++) 
	{
		for (j=0; j<20; j++) 
		{
			if (m[i][j]==1) 
			{
				printf ("*");
			}
			else printf (" ");
		}
		printf ("\n");
	}
	return 0;
}
