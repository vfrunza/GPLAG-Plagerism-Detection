#include <stdio.h>
#define donjiLimit 0
#define gornjiLimit 100

int main() {
	int m, n, o, i, teplicova, cirkularna;
	double matrica[gornjiLimit] [gornjiLimit];
	
	o = 0;
	teplicova = 0;
	cirkularna = 0;
	
	do
	{
		if (o == 1)
		{
			printf("Pogresan unos!\n");
		}
		printf("Unesite M i N: ");
		scanf("%i %i", &m, &n);
		o = 1;
	} while ((m <= donjiLimit || m > gornjiLimit) || (n <= donjiLimit || n > gornjiLimit));
	
	printf("Unesite elemente matrice: ");
	
	for (i = 0; i < m; i++)
	{
		for (o = 0; o < n; o++)
		{
			scanf("%lf", &matrica[i][o]);
		}
	}
	
	for (i = 0; i < m-1; i++)
	{
		for (o = 0; o < n-1; o++)
		{
			if (matrica[m-1][n-1] != matrica [m-2][n-2])
			{
				teplicova = 0;
			}
			
			if (matrica [i][o] == matrica [i+1][o+1])
			{
				teplicova = 1;
			}
			
			else if (matrica [i][o] != matrica [i+1][o+1])
			{
				teplicova = 0;
				o = n;
				i = m;
				break;
			}
		}
	}
	
	for (i = 0; i < m-1; i++)
	{
		for (o = 0; o < n-1; o++)
		{
			if ((matrica[i][n-1] == matrica[i+1][0]))
			{
				cirkularna = 1;
			}
			
			else if ((matrica[i][n-1] != matrica[i+1][0]))
			{
				cirkularna = 0;
				i = m;
				o = n;
				break;
			}
		}
	}
	
	if (n == 1 && m == 100)
	{
		printf("Matrica je Teplicova");	
		return 0;
	}
	
	if (n == 1 || m == 1)
	{
		printf("Matrica je cirkularna");
		return 0;
	}
	
	if (teplicova == 1)
	{
		if (cirkularna == 1)
		{
			printf("Matrica je cirkularna");
		}
		else
		{
			printf("Matrica je Teplicova");	
		}
	}
	else
	{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	return 0;
}
