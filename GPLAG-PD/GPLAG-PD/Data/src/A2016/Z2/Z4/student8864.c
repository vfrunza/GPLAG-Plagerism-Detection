#include <stdio.h>
int main() {
	int m=0,n=0,teplicova=1,cirkularna=0,i,j;
	double niz[100][100]={{0}};
	ponovi:
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if((m<=0 || m>100) || (n<=0 || n>100))
	{
		printf("Pogresan unos!\n");
		goto ponovi;
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&niz[i][j]);
		}
	}
	if(m==1 && n==1)
	{
		printf("Matrica je cirkularna");
		return 0;
	}
	else if(m==1)
	{
		printf("Matrica je cirkularna");
		return 0;
	}
	/*else if(niz[0][n-1]==niz[1][0] && niz[1][n-1]==niz[2][0] && niz[2][n-1]==niz[3][0])
	{
		cirkularna=1;	
	}*/
	/*for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(niz[i][j]==niz[i+1][0]) 
			{
				cirkularna=1;	
			}
		}
	}*/
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(niz[i][j]!=niz[i+1][j+1]) 
			teplicova=0;
		}
	}
	if(cirkularna==1)
	{
		printf("Matrica je cirkularna");
	}
	else if(teplicova==1)
	{
		printf("Matrica je Teplicova");
	}
	else if(teplicova==0 && cirkularna!=1)
	{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
