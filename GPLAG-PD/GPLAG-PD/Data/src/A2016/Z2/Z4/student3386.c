#include <stdio.h>
#define BE 100
int main() {
	int m,n,i,j,cirk,tepl;
	double matrica[BE][BE];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m>100 || m<=0 || n>100 || n<=0)
	printf("Pogresan unos!\n");
	}while(m>100 || m<=0 || n>100 || n<=0);
	printf("Unesite elemente matrice: ");
	cirk=1;
	tepl=1;
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&matrica[i][j]);
		}
	}
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if((matrica[i][n-1]!=matrica[i+1][0]) || (matrica[i][j]!=matrica[i+1][j+1]))
			cirk=0;
			
		}
	}
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(matrica[i][j]!=matrica[i+1][j+1])
			tepl=0;
			
		}
	}
	if((tepl==1 && cirk==0) || (m==100 && n==1))
	printf("Matrica je Teplicova");
	else if(cirk==1 && tepl==1)
	printf("Matrica je cirkularna");
	else
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}