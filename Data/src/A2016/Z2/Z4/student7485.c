#include <stdio.h>
#include <math.h>

int main() {
	int i,j,n,m,T=1,C=0;
	double a[100][100];
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&n,&m);
	if(m>100||n>100||n<1||m<1) printf("Pogresan unos!\n");
	}while(m>100||n>100||n<1||m<1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<m-1;j++){
			if (a[i][j]!=a[i+1][j+1]) T=0;
		}
	}
	if (T)
	{
		C=1;
		for(i=0;i<n-1;i++)
		{
			if(fabs(a[i][m-1]-a[i+1][0])>0.0001)
			{
				C=0;
			}
		}
	}
	if (C||n==1) printf("Matrica je cirkularna");
	else if (T||m==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
