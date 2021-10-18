#include <stdio.h>
#include <math.h>
int main() {
	double a[100][100];
	int m,n,i,j,s=0,p=0,y;
	y=0.0001;
while(1)	{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		if (m>=1 && m<=100 && n>=1 && n<=100 )		break;
		printf("Pogresan unos!\n");
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
		scanf("%lf",&a[i][j]);
	if(m>1 && n>1){	
		for(i=0;i<(m-1);i++)	{
		for(j=0;j<(n-1);j++)	{
		if (fabs(a[i][j]-a[i+1][j+1])>y || fabs(a[i][n-1]-a[i+1][0])>y)    
		{	
			s++; i=m-1; j=n-1; 	}
		}
	 	}
	 for(i=0;i<(m-1);i++){
	 	for(j=0;j<(n-1);j++){
	 		if(fabs(a[i][j]-a[i+1][j+1])>y){
	 			p++; i=m-1; j=n-1;
	 		}
	 	}
	 }
	}
	else if(m==1 && n==1 || n>m)  s=0;
	else if(m>n)   s=1;
	if(s==0)
	printf("Matrica je cirkularna");
	else if(s==1 && p==0)
	printf("Matrica je Teplicova");
	else 
	printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
