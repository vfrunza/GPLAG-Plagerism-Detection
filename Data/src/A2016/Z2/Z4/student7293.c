#include <stdio.h>

int main() 
{
	double	mat [100][100];
	int m,n,i,j,x=0;
	
	do
	{
		printf ("Unesite M i N: ");
		scanf("%d %d", &m,&n);	
		if (m<1 || m>100 || n<1 || n>100)
		{
			printf ("Pogresan unos!\n");
		}
	}
	while (m<1 || m>100 || n<1 || n>100);

		printf ("Unesite elemente matrice: ");
		for (i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf ("%lf", &mat[i][j]);
			}
		}
	
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			if (mat[0][j]!=mat[i][(i+j)%n])
			{
				x=1;
			}
		}
	}
	
	if (x==0)
	{
		printf ("Matrica je cirkularna");
		return 0;
	}
	
	x=0;
	for (i=0; i<m-1; i++)
	{
		for (j=0; j<n; j++)
		{
			if (j+1<n)
			{
				if (mat[i][j]!=mat[i+1][j+1])
				{
					printf ("Matrica nije ni cirkularna ni Teplicova");
					return 0;
				}
			}
		}
	}
	
	printf ("Matrica je Teplicova");
	
	return 0;
}
