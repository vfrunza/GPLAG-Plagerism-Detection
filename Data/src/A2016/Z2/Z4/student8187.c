#include <stdio.h>

int main() {
	int teplicova=1, cirkularna=1, i, j, m, n;
	double mat[100][100];
	do 
	{	
	printf ("Unesite M i N: ");
	scanf ("%d %d", &m,&n);
	while (m<1 || n<1 || m>100 || n>100)
		{
			printf ("Pogresan unos!\nUnesite M i N: ");
			scanf ("%d %d", &m,&n);
		}
		
	}
	while (m<1 || n<1 || m>100 || n>100);
	
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf ("%lf", &mat[i][j]);
		}
	}

	for (i=1; i<m; i++)
		{
			if (mat[i][0]!=mat[i-1][n-1])
			{
				cirkularna=0;
			}
		
			for (j=1; j<n; j++)
			{
				if (mat[i][j]!=mat[i-1][j-1])
				{
					cirkularna=0;
				}
			}
		}			
	
	for (i=1; i<m; i++)
	{
		for (j=1; j<n; j++)
			{
				if (mat[i][j]!=mat[i-1][j-1]) 
				{
					teplicova=0;
				}
			}
	}
	
	if (cirkularna==1) 
	{
		printf ("Matrica je cirkularna");
		
	}
	else if (teplicova==1)
	{
		printf ("Matrica je Teplicova");
	}
	
	else
	{
		printf ("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
