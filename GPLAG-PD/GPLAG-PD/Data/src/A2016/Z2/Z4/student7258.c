#include <stdio.h>

int main() {
	int M,N;
	do {
	printf("Unesite M i N: ");
	scanf("%d %d",&M,&N);
	if(M<=0 || M>100 || N<=0 || N>100) printf("Pogresan unos!\n");
	} while (M<=0 || M>100 || N<=0 || N>100);
	int mat[100][100],i,j;
	printf("Unesite elemente matrice: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%f",&mat[i][j]);
		}
	}
	int C=1;
	for(j=0;j<N;j++) {
		for(i=0;i<M;i++) {
			if(mat[0][j]!=mat[i][(j+i)%N]) {
				C=0;
			}
		}
	}

	int T=1;
	for(i=0;i<M-1;i++) {
		for(j=0;j<N-1;j++) {
			if (mat[i][j]!=mat[i+1][j+1]) {
				T=0;
			}
		}
	}
	if(C) {
		printf("Matrica je cirkularna\n");
	} else if(T) {
		printf("Matrica je Teplicova\n");
	} else  {
		printf("Matrica nije ni cirkularna ni Teplicova\n");
	}
	return 0;
}
