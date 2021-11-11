#include <stdio.h>

int main() {
	int i, j, k, p, q, m, n, isti, mat[200][200];
	do{
		printf ("Unesite brojeve M i N: ");
		scanf ("%d %d", &m, &n);
		if (m < 1 || m > 200 || n < 1 || n > 200)
		printf ("Brojevi nisu u trazenom opsegu.\n");
	}while (m < 1 || m > 200 || n < 1 || n > 200);
	
	printf ("Unesite elemente matrice: ");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		scanf ("%d", &mat[i][j]);
	
	
		
	for (i = 0; i < m-1; i++)
		for (j = i+1; j < m; j++)
		{
			isti = 1;
			for (k = 0; k < n; k++)
				if (mat[i][k] != mat[j][k])
				{
					isti = 0; 
					break;
				}
		if (isti)
		{
			if (j == m)
			{
				m--;
				continue;
			}
			for (p = j; p < m-1; p++)
				for(q = 0; q < n; q++)
					mat[p][q] = mat[p+1][q];
			m--;
			j--;
		}
		}
	
	for (i = 0; i < n-1; i++)
		for (j = i+1; j < n; j++)
		{
			isti = 1;
			for (k = 0; k < m; k++)
				if (mat[k][i] != mat[k][j])
				{
					isti = 0;
					break;
				}
			if (isti)
			{
				if (j == n)
				{
					n--;
					continue;
				}
				for (p = j; p < n-1; p++)
					for (q = 0; q < m; q++)
						mat[q][p] = mat[q][p+1];
				n--;
				j--;
			}
		}
	
	printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf ("%5d", mat[i][j]);
		printf ("\n");
	}
	return 0;
}
