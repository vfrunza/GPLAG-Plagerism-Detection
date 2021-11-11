#include <stdio.h>
#include <math.h>
#define EPS 0.00000001
int main() {
	int t1=1,tep=1,cir=1,x,k,i,j,m,n;
	double t=0,mat[100][100];
	do {
		printf ("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if (m<1 || m>100 || n<1 || n>100)
			printf ("Pogresan unos!\n");
	} while (m<1 || m>100 || n<1 || n>100);
	printf("Unesite elemente matrice: ");
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) 
			scanf ("%lf",&mat[i][j]);
	}
		for (i=0;i<m-1;i++) {
			for (j=0;j<n-1;j++) {
				if ((mat[i][j]!=mat[i+1][j+1]) || (mat[i][n-1]!=mat[i+1][0])) cir=0;
					if (mat[i][j]!=mat[i+1][j+1]) tep=0;
				}
			}
	if (n==1) {
		for (i=0;i<m;i++) {
			for (j=0;j<n;j++) {
				if (i==0 && j==0) k=mat[i][j];
				if (k!=mat[i][j]) break;
			}
		}
		if (j==n) printf ("Matrica je cirkularna");
		else printf ("Matrica je Teplicova");
		return 0;
	}
	if (m==1) {
		printf ("Matrica je cirkularna");
		return 0;
	}
	if (tep) {
		if (cir) {
			printf ("Matrica je cirkularna");
			return 0;
		}
		else { 
			printf ("Matrica je Teplicova");
			return 0;
		}
	}
	printf ("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
