#include <stdio.h>
#include<math.h>

int main() {
	int m,n,i,j,brojac=0;
	const double eps=1e-2;
	double a[100][100];
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	do {
	        if((m<=0 || m>100) || ( n>100 || n<=0)) {
           	printf("Pogresan unos!\n");
           	printf("Unesite M i N: ");
           		scanf("%d %d",&m,&n);}
	} while ((m<=0 || m>100) || ( n>100 ||  n<=0));
	printf("Unesite elemente matrice: ");
	
	for(i=0;i<m;i++)
		for(j=0;j<n;j++) 
		scanf("%lf",&a[i][j]);
	
	for(i=0;i<m-1;i++)
		for(j=0;j<n-1;j++)
 if(fabs(a[i][j]-a[i+1][j+1])>eps) brojac++;
			
			if(brojac!=0) 
			printf("Matrica nije ni cirkularna ni Teplicova");
			else { for(j=0;j<m-1;j++)
			if(fabs(a[j][n-1]-a[j+1][0])>eps)brojac++;
			if(brojac!=0) printf("Matrica je Teplicova");
			else printf("Matrica je cirkularna"); }
	return 0;
}
