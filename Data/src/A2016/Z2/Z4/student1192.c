#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
#include <stdlib.h>
int main() {
	int i,t,c,  j,   m, n;
	double a[100][100];
	do
	{
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	if((m>100)||(m<=0)||(n>100)||(n<=0))
	printf("Pogresan unos!\n");
	}
	while((m>100)||(m<=0)||(n>100)||(n<=0));
	printf("Unesite elemente matrice: ");
	t=1;
	c=1;
	for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
				{
					scanf("%lf", &a[i][j]);
				}
		}
		for(i=0; i<m-1; i++)
		{
			
			for(j=0; j<n-1; j++)
			{
				if(fabs(a[i][j]-a[i+1][j+1])>epsilon)
				{
					t=0;
				}
			
			}
			
		}
		if(t==1)
		{
		for(i=0; i<m-1; i++)
		{
			if(fabs(a[i][n-1]-a[i+1][0])>epsilon)
				c=0;
			
			
		}	
		}
	if(t==1)
	{
		if(c==1)
		printf("Matrica je cirkularna");
		else 
		printf("Matrica je Teplicova");
	}
	else 
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
