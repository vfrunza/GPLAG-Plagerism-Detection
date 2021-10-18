#include <stdio.h>
#define MAX 100
#define EPSILON 0.0001
#include <math.h>

int main() {
	int m, n;
	double matrica[MAX][MAX];
	int i, j, a=1, b=1;
	do 
	{
	    printf("Unesite M i N: ");
	    scanf("%d %d", &m, &n);
	    if ((m<=0 || m>100) || (n<=0 || n>100))
	    {
	        printf("Pogresan unos!\n");
	        continue;
	    }
	} while ((m<=0 || m>100) || (n<=0 || n>100));
	
	printf("Unesite elemente matrice: ");
	for (i=0; i<m; i++)
	{
	    for (j=0; j<n; j++)
	    {
	       scanf(" %lf", &matrica[i][j]);
	    }
	}
	
	
	if(n>1 && m>1)
	{
		for (i=0; i<m; i++)
		{
			if(i==m-1)
			break;
			for(j=0; j<n; j++)
			{
				if (j==n-1)
				break;
				else
				{
					if(fabs(matrica[i][j]-matrica[i+1][j+1])>EPSILON)
					{
						a=0;
						goto kraj;
					}
				}
			}
		}
		
	kraj:
	
	if (a)
	{
		for (i=0; i<m; i++)
		{
			if(i==m-1)
			break;
			if(fabs(matrica[i][n-1]-matrica[i+1][0])>EPSILON)
			{
				b=0;
				goto prekid;
			}
			
		}
		prekid:
		
		if(b)
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
	}
	else if (n==1 && m==1)
	{
		printf("Matrica je cirkularna");
	}
	else if (m==1)
	{
		printf("Matrica je cirkularna");
	}
	else if (n==1)
	{
		printf("Matrica je Teplicova");
	}
	
	
	return 0;
}
