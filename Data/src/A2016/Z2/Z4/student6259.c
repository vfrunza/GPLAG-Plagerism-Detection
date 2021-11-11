#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
	
	double mat[100][100];
	int m, n, i, j, k;
	int Teplicova=0, Cirkularna=0;
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &m, &n);
		
		if(m<1 || m>100 || n<1 || n>100) printf("Pogresan unos!\n");
		
	}
	
	while(m>100 || m<1 || n>100 || n<1);
	
	
	printf("Unesite elemente matrice: ");
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf", &mat[i][j]);
			
		}
	}
	
	if(n>=1 && m==1) {Cirkularna=1; Teplicova=1;}
	else if(n==1 && m>=1) Teplicova=1;
	else {
		for(i=1; i<m; i++) {
			for(j=1; j<n; j++) {
				Teplicova=1;
				if(fabs(mat[i][j]-mat[i-1][j-1])>EPSILON) { 
					Teplicova=0;
					break;
				}
			}
		}
	
	
		if(Teplicova==1) {
			for(k=1; k<m; k++) {
				Cirkularna=1;
				if(fabs(mat[0][n-k]-mat[k][0])>EPSILON) {
					Cirkularna=0;
					break;
				}
			}
		}
	}
	
	if (Teplicova==1 && Cirkularna==1) printf("Matrica je cirkularna");
	else if (Teplicova==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
