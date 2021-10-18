#include <stdio.h>

int main() {
	int i,j,m,n;
	double matrica[100][100];
	
	do
	{
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || n<=0 || m>100 || n>100)printf("Pogresan unos!\n");
	
	
	} while(m<=0 || n<=0 || n>100 || m>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&matrica[i][j]);
		}
	}
	
	int teplicova=1, cirkularna=1;
	
	for (i=0;i<m-1;i++)
	{
		for(j=0;j<n-1;j++)
		{   
			if(matrica[i][j]!=matrica[i+1][j+1]){ teplicova=0; break; } 
		}
	}
	if(teplicova==0) cirkularna=0;
	if(teplicova==1) {
	for (i=0;i<m-1;i++)
	{
		if(matrica[i][n-1]!=matrica[i+1][0]) { cirkularna=0; break;}
	}
	}
	
	if(teplicova==1 && cirkularna==0) printf("Matrica je Teplicova");
	if(cirkularna==1) printf("Matrica je cirkularna");
	if(teplicova==0 && cirkularna==0) printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
