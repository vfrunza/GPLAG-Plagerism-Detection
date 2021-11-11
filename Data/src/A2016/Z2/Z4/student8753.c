#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.000001
int main() {
	double matrica[100][100]; 
	int i,j,M,N,teplicova=1,cirkularna=1;
	do {
		printf ("Unesite M i N: ");
		scanf ("%d", &M);
		scanf ("%d", &N);
		if (M>100 || N>100 || M<=0 || N<=0){
			printf ("Pogresan unos!\n");
		}
		
	}
	while (M>100 || N>100 || M<=0 || N<=0);
	printf ("Unesite elemente matrice: ");
	for (i=0;i<M;i++){
		for (j=0;j<N;j++){
			scanf ("%lf", &matrica[i][j]);
		}
	}
	 for (i=0;i<M-1;i++){
	 	if (teplicova==0){
	 	break;
	 	}
	 	for (j=0;j<N-1;j++){
	 		if (fabs(matrica[i][j]-matrica[i+1][j+1])>EPSILON){
	 			teplicova=0;
	 			cirkularna=0;
	 		}
	 	}
	 }
	 if (teplicova==1){
	 	for (i=1;i<M;i++) {
	 		if (cirkularna==0)
	 		break;
	 		if (fabs(matrica[i][0]-matrica[i-1][N-1])>EPSILON){
	 			cirkularna=0;
	 		}
	 	}
	 }
	 if (cirkularna==1)
	 printf ("Matrica je cirkularna");
	 else if (teplicova==1 && cirkularna==0){
	 	printf ("Matrica je Teplicova");}
	 else printf ("Matrica nije ni cirkularna ni Teplicova");

















	return 0;
}
