#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
	int m,n,i,j,cirkularna,teplicova;
	double mat[100][100];
	do {
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1 || m>100 || n<1 || n>100)
			printf("Pogresan unos!\n");
	} while(m<1 || m>100 || n<1 || n>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%lf",&mat[i][j]);
		}
	}
	if(m==1)
		printf("Matrica je cirkularna");
	else if(m!=1 && n==1)
		printf("Matrica je Teplicova");
	else {
	cirkularna=1;					
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			if((i<m-1 && j<n-1 && fabs(mat[i][j]-mat[i+1][j+1])>EPSILON) || (j==n-1 && i<m-1 && fabs(mat[i][j]-mat[i+1][0])>EPSILON)) {
				cirkularna=0;
				i=m;
				j=n;
			}
		}
	}
	teplicova=1;					
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			if(i<m-1 && j<n-1 && fabs(mat[i][j]-mat[i+1][j+1])>EPSILON) {
				teplicova=0;
				i=m;
				j=n;
			}
		}
	}
	if(cirkularna==1)
		printf("Matrica je cirkularna");
	else if(cirkularna==0 && teplicova==1)
		printf("Matrica je Teplicova");
	else
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
