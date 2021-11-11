#include <stdio.h>
#include <math.h>
#define e 0.00001

int main() {
	double a[100][100];
	int m, n, i, j, D=0, V=0;
	printf ("Unesite M i N: ");
	scanf ("%d %d", &m, &n);
	do{
		if (m>100||n>100||m<1||n<1)
		{
			printf ("Pogresan unos!\n");
			printf ("Unesite M i N: ");
			scanf ("%d %d", &m, &n);
		}
	} while (m>100||n>100||m<1||n<1);
	printf ("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf ("%lf", &a[i][j]);
		}
	}
	for (j=0; j<n; j++)
	{
		for (i=0; i<m; i++)
		{
			if (fabs(a[0][j]-a[i][(i+j)%n])>0)
			V++;
		}
	}
	if (V==0)
	{
		printf ("Matrica je cirkularna\n");
	}
	else{
	for (i=0; i<(m-1); i++)
	{
		for (j=0; j<(n-1); j++)
		{
			if (fabs(a[i][j]-a[i+1][j+1])>0)
			{
				D++;
			}
		}
	}
	if (D>0)
	{
		printf ("Matrica nije ni cirkularna ni Teplicova\n");
	}
		else 
		printf ("Matrica je Teplicova\n");
	}
	return 0;
}
