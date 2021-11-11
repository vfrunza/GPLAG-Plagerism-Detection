#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.000000000000000000000001

int main()
{
	double matrica[100][100];
	int m, n, i = 0, j, JeLiSeDesioBreak = 0;
	do
	{
		if (i > 0) printf ("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf ("%d %d", &m, &n);
		i++;
	}while (m <= 0 || m > 100 || n <= 0 || n > 100);

	printf ("Unesite elemente matrice: ");
	for (i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf ("%lf", &matrica[i][j]);
		}
	}

	for (i = 0; i < m - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (fabs (matrica[i][j] - matrica[i+1][j+1]) > eps)
			{
				JeLiSeDesioBreak++;
				break;
			}
		}

		if (JeLiSeDesioBreak == 1)
		{
			printf ("Matrica nije ni cirkularna ni Teplicova");
			break;
		}
	}

	if (JeLiSeDesioBreak == 0)
	{
		for (i = 0; i < m-1; i++)
		{
			if (m == 1)
				break;
			for (j = 0; j < n; j++)
			{
				if (fabs (matrica[i][n-1] - matrica[i+1][0]) > eps)
				{
					JeLiSeDesioBreak++;
					printf("Matrica je Teplicova");
					break;
				}
				
			}
			if (JeLiSeDesioBreak == 1)
			break;
		}
		if (JeLiSeDesioBreak == 0)
		printf ("Matrica je cirkularna");

	}
	return 0;
}
