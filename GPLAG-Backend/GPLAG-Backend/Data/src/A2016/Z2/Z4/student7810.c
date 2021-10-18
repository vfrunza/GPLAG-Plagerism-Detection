#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define EPSILON 0.0001
int main() {
	int M,N,cirkularna=1,teplicova=1,i,j;
	double matrica[100][100];
	do {
		printf("Unesite M i N: ");
	    scanf ("%d %d",&M,&N);
	    if (M<=100 && M>0 && N<=100 && N>0) break;
	    printf("Pogresan unos!\n");
	}while(1);
	printf("Unesite elemente matrice: ");
	for (i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&matrica[i][j]);
		}
	}
	if (M==1 && N==1) {printf("Matrica je cirkularna"); return 0;}
	else if (N==1) {printf("Matrica je Teplicova"); return 0;}
	for (i=0;i<M-1;i++){
	    for(j=0;j<N-1;j++){
			if (fabs(matrica[i][j]-matrica[i+1][j+1])>EPSILON || fabs(matrica[i][N-1]-matrica[i+1][0])>EPSILON) {
				cirkularna=0;
			i=j=500;
			}
			
		}
	}
	if (cirkularna==0) {
		for (i=0;i<M-1;i++){
	        for(j=0;j<N-1;j++){
			    if (fabs(matrica[i][j]-matrica[i+1][j+1])>EPSILON){
			    	 teplicova=0;
			         i=j=500;
			    }
	        }
	    }	   
	}
	if (cirkularna==1) printf("Matrica je cirkularna");
	else if (teplicova==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
