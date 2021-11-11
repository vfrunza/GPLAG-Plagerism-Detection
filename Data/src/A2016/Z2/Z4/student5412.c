#include <stdio.h>
#define BROJ_EL 100

int main() 
{
	int mat[BROJ_EL][BROJ_EL], i, j, m, n;
	int tep = 0, cir = 0;
	do
	{
		printf ("Unesite M i N: ");
		scanf ("%d %d", &m, &n);
		if (n<=0 || n>=100 && m<=0 || m>100) printf ("Pogresan unos!\n");
	}while (n<=0 || n>=100 && m<=0 || m>=100);
	
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf ("%d", &mat[i][j]);
		}
	}
	
	for (i=0; i<m-1; i++) 
	{
		for (j=0; j<n-1; j++) 
		{
			if (mat[i][j] != mat[i+1][j+1])
			tep = 1;
		}
	}
	
	for (i=1; i<m; i++) 
	{
		for (j=1; j<n-1; j++) 
		{
			if (mat[i-1][n-1] != mat[i][0])
			cir = 1;
		}
	}
	
	if (cir == 0 && tep == 0) printf ("Matrica je cirkularna");
	else if (tep == 0 && cir == 1) printf ("Matrica je Teplicova");
	else printf ("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
