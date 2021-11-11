#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.000000000000000000000001
int main() {
	double matrica[100][100];
	int m,n,i=0,j,JeLiSeDesioBreak=0;
	do
	{
		if(i>0)printf("Pogresan unos!\n");
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		i++; 
	}while (m<=0 || m>100 || n<=0 || n>100);
	
	printf ("Unesite elemente matrice: ");
	
	i=0;
	while (i<m)
	{
		j=0;
		while (j<n)
		{
			scanf("%lf", &matrica[i][j]);
			j++;
	}
	i++;
	}
	
	i=0;
	for(;i<m-1; i++)
	{
		j=0;
		while (j<n-1)
		{
			if(fabs (matrica[i][j]-matrica[i+1][j+1])>eps)
		{
			JeLiSeDesioBreak++;
			break;
			}
			j++;
		}
		if (JeLiSeDesioBreak==1)
		{
			printf("Matrica nije ni cirkularna ni Teplicova");
			break;
		}
	}
		
		if (JeLiSeDesioBreak==0)
		{
			i=0;
			for (;i<m-1;i++)
			{
				if (m==1)
					break;
				j=0;
				while(j<n)
				{
					if(fabs (matrica[i][n-1]-matrica[i+1][0])>eps)
				{
					JeLiSeDesioBreak++;
					printf("Matrica je Teplicova");
					break;
				}
				j++;
				}
				if (JeLiSeDesioBreak==1)
				break;
			}
			if (JeLiSeDesioBreak==0)
			printf ("Matrica je cirkularna");
			
			
		}
	return 0;
}