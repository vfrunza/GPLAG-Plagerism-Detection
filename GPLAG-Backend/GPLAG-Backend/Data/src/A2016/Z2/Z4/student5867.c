#include <stdio.h>
#include <math.h>

int main() 
{
	int i, j, m, n, cirkularna=0, teplicova=0;
	double mat[100][100];
	const double epsilon = 1e-10;
	
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	do
	{
		{
		if (m<=0 || m>100 || n<=0 || n>100)
		{
		printf("Pogresan unos!");
		printf("\nUnesite M i N: ");
		scanf("%d %d", &m, &n);
		continue;
		}
		else break;
	}
	}
	while(5);
	
	/*for(i=0; i<1; i++)
	{
	if(m<=0 || m>100 || n<=0 || n>100)
	{
		printf("Pogresan unos!");
		printf("\nUnesite M i N: ");
		scanf("%d %d", &m, &n);
		i--;
		}
		else break;
	}*/
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
	
	if((m==1 && n==1) || (m==1))
	{
		printf("Matrica je cirkularna");
		return 0;
	}
	
	if(n==1)
	{
	printf("Matrica je Teplicova");
	return 0;
	}
	
	for(i=1; i<m; i++)
	{
		for(j=1; j<n; j++)
		{
			if(fabs((mat[i-1][n-1]-mat[i][0])>epsilon && fabs((mat[i-1][j-1]-mat[i][j])>epsilon)))
			{
			cirkularna=0;
			break;
		}
			if(mat[i-1][n-1]==mat[i][0] && mat[i-1][j-1]==mat[i][j])
			cirkularna=1;
			else 
			{
				//if(fabs(mat[i-1][n-1]-mat[i][0]>EPSILON) && fabs(mat[i-1][j-1]-mat[i][j]>EPSILON))
				cirkularna=0;
				break;
			}
		}
		if(cirkularna==0)
		break;
	}
		
		for(i=1; i<m; i++)
		{
			for(j=1; j<n; j++)
			{
				if(mat[i-1][j-1]==mat[i][j])
				teplicova=1;
				else
				{
					if(fabs(mat[i-1][j-1]-mat[i][j])>epsilon)
					teplicova=0;
					break;
				}
			}
			if(teplicova==0)
			break;
		}
	
	
	if(cirkularna)
	printf("Matrica je cirkularna");
	else if(teplicova)
	printf("Matrica je Teplicova");
	else if(cirkularna==1 && teplicova==1)
	printf("Matrica je Teplicova");
	else if(teplicova==1 && cirkularna==0)
	printf("Matrica je Teplicova");
	else if(cirkularna==0 && teplicova==0)
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
