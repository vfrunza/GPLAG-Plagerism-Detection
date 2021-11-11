#include <stdio.h>


int main()
{
	int m,n,i,j;
		
	do {
		printf("Unesite M i N: ");
	     scanf("%d %d",&m,&n);
		if((m<=0 || m>100) || (n<=0 || n>100)){
			 printf("Pogresan unos!\n");
             
}
	} while((m<=0 || m>100) || (n<=0 || n>100));
	double a[100][100];
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++)
			scanf("%lf",&a[i][j]);

	}
	int teplicova=1;
	for(i=0; i<m-1; i++) {
		for(j=0; j<n-1; j++) {
			if(a[i][j]!=a[i+1][j+1]) {
				teplicova=0;
				          i=m;
				j=n;
			}
		}
	}
    	int cirkularna=1;
	if(teplicova==0) printf("Matrica nije ni cirkularna ni Teplicova");
	else {

		for(i=0; i<m-1; i++) {
			for(j=0; j<n; j++) {
				if(a[i][n-1]!=a[i+1][0] ) {
					cirkularna=0;
					i=m;
					j=n;

				}
			}
		}
		if(cirkularna==1) printf("Matrica je cirkularna");
else printf("Matrica je Teplicova");
	}












	return 0;
}
