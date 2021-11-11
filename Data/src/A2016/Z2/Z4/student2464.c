#include <stdio.h>

int main() {
	int m, n, i, j, k, t=1, c=1, lim, pr;
	double a[105][105]; 
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if (m<=0 || m>100 || n<=0 || n>100) printf("Pogresan unos!\n");
	}while (m<=0 || m>100 || n<=0 || n>100);
	printf("Unesite elemente matrice: ");
	for (i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	if (m==1)
	{
		printf("Matrica je cirkularna");
		return 0;
	}
	if (n==1)
	{
		for (i=0;i<m;i++)
		{
			if (a[i][0]!=a[0][0]) c=0;
		}
		if (c) 
		{
			printf("Matrica je cirkularna");
			return 0;
		}
		else
		{
			printf("Matrica je Teplicova");
			return 0;
		}
	}
	for (i=0;i<m-1;i++)
	{
		for (j=0;j<n-1;j++)
		{
			if (a[i][j]!=a[i+1][j+1]) t=0;
		}
	}
	if (t)
	{
		for (i=0;i<m-1;i++)
		{
			for (j=0;j<n;j++)
			{
				if (j==n-1)
				{
					if (a[i][j]!=a[i+1][0]) c=0;
				}
				else if (a[i][j]!=a[i+1][j+1]) c=0;
			}
		}
		if(c) printf("Matrica je cirkularna");
		else printf("Matrica je Teplicova");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
