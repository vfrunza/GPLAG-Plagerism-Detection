#include <stdio.h>
#include <math.h>
#define E 0.0001
int main() {
	int m,n,i,j,t=0,c=0;
	double a[100][100]={{0}};
	do
	{
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m<=0 || m>100 || n<=0 || n>100)
	printf("Pogresan unos!\n");
	}
	while(m<=0 || m>100 || n<=0 || n>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	
		for(j=0;j<n;j++)
		{
			scanf("%lf",&a[i][j]);
		}
		
		for(i=0;i<m-1;i++)
		{
		for(j=0;j<n-1;j++)
		{
		if(fabs(a[i][j]-a[i+1][j+1])<E)
		t=1;
		else
		{
		t=0;
		break;
		}
		
		}
		if(t==0)
		break;
		}
		
		for(i=0;i<m-1;i++)
		{
		for(j=0;j<n-1;j++)
		{
		if(t==1 && (fabs(a[i][n-1]-a[i+1][0])<E))
		c=1;
		else
		{
		c=0;
		break;
		}
		}
		if(c==0)
		break;
		}
		if(c==1 || m==1)
		printf("Matrica je cirkularna");
		else
		if(t==1 || n==1)
		printf("Matrica je Teplicova");
		else
		printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
