#include <stdio.h>
#include <math.h>

int main() {
	int i, j, m, n, teplicova, cirkularna;
	double mat[100][100];
	
	do
	{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		
		if(m<1 || m>100 || n<1 || n>100) printf("Pogresan unos!\n");
	}while(m<1 || m>100 || n<1 || n>100);
	
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	
	teplicova=0;
	cirkularna=0;
	if(m==1)
	{
		printf("Matrica je cirkularna");
		return 0;
	}
	else if(n==1)
	{
		printf("Matrica je Teplicova");
		return 0;
	}
	else
	{
		for(i=0;i<m-1;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(fabs(mat[i][j]-mat[i+1][j+1])<0.000000001)
				{
					teplicova=1;
				}
				else
				{
					teplicova=0;
					break;
				}
			}
		}
	
		
		for(i=0;i<m-1;i++)
		{
			if(fabs(mat[i][n-1]-mat[i+1][0])<0.0000000001)
			{
				cirkularna=1;
			}
			else
			{
				cirkularna=0;
				break;
			}
		}
	}
	
	if(cirkularna==1 && teplicova==1) printf("Matrica je cirkularna");
	else if(teplicova==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
