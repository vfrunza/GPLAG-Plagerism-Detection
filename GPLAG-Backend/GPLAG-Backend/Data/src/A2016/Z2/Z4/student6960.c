#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define VISINA 20
#define SIRINA 20
#define A 0.0001

int main() {
	int M,N,i,j,m,n;
	int matrica[VISINA][SIRINA];
	int b=1;
	do {
		printf("Unesite M i N: ");
		scanf("%d %d",&M,&N);
		if (M>100 || N>100 || M<=0 || N<=0) printf("Pogresan unos!\n");
	} while (M>100 || N>100 || M<=0 || N<=0);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf("%lf",&matrica[i][j]);
			}
	}
	
	for(m=0;m<M-1;m++) {
		for (n=0;n<N-1;n++) {
			if(fabs(matrica[m][N-1]-matrica[m+1][0])>A) {
			b=2;
		break;
			}
			if(fabs(matrica[m][n]-matrica[m+1][n+1])>A) {
				b=3;
			break;
			}
		}
	}
	
	if(b==3) printf("Matrica je cirkularna");
	if(b==2) printf("Matrica je Teplicova");
	else if(b==1) printf("Matrica nije ni cirkularna ni Teplicova");


	return 0;
}
