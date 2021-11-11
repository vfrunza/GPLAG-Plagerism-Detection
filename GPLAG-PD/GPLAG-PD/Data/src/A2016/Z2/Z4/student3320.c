#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define epsilon 0.000001
#define visina 100
#define sirina 100

int main() {
	
	int m, n;
	double mat[visina][sirina];
	int i, j;
	int Cbrojac=1;

	do {
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	if(((m<=0) || (m>100)) || ((n<=0) || (n>100))) {
		printf("Pogresan unos!\n");
	}
	}while ((m<=0) || (m>100) || (n<=0) || (n>100));
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	
	if(n==1 && m!=1) {
			printf("Matrica je Teplicova");
			return 0;
		}
	
	for(i=0; i<m-1; i++) {
		for(j=0; j<n-1; j++) {
			
			if((fabs(mat[i][j]-mat[i+1][j+1]))>epsilon) {
				printf("Matrica nije ni cirkularna ni Teplicova");
				return 0;
			}
				
			if((fabs((mat[i][n-1])-(mat[i+1][0])))>epsilon) {
				Cbrojac=0;
			}
				
		
	/*		if((abs((mat[i][j])-(mat[i+1][j+1])))<epsilon)
				Tbrojac=1;
			*/

			}
		}

	if(Cbrojac==1) {
		printf("Matrica je cirkularna");
		return 0;
	} else {
			printf("Matrica je Teplicova");
			return 0;
	}
		


/*	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%d  ", mat[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}
