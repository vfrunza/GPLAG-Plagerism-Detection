#include <stdio.h>
#define BR_EL 200

int main() 
{
	int i, j, mat[BR_EL][BR_EL], m, n, redovi=0, kolone=0;
	do
	{
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &m, &n);
		if (m<=0 || m>200 || n<=0 || n>200) printf ("Brojevi nisu u trazenom opsegu.\n");
	}while (m<=0 || m>200 || n<=0 || n>200);
	
	
    printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf ("%d", &mat[i][j]);
		}
	}
	
	 for (i=0; i<m; i++)
	 {
	 	for (j=i; j<m; j++)
	 	{
	 		redovi = mat[0][0];
	 		if (redovi == i+1)
	 		{
	 			mat[redovi+1][j] = mat[m-1][j];
	 		}
	 		redovi--;
	 	}
	 }
	
	 for (i=0; i<n; i++)
	 {
	 	for (j=i; j<n; j++)
	 	{
	 		kolone = mat[0][0];
	 		if (kolone == i+1)
	 		{
	 			mat[kolone+1][j] = mat[n-1][j];
	 		}
	 		kolone--;
	 	}
	 }

	
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");

	for (i=0; i<m-1; i++)
	{
		for(j=0; j<n-1; j++)
		{
			printf ("    %d", mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
