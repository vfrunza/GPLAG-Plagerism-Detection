#include <stdio.h>
#include <math.h>
#define e 0.0001

int main() {
	int M, N, i, j, t=1, c=1;
	double mat[100][100];

	for(i=0; i<100; i++) {
		for(j=0; j<100; j++) {
			mat[i][j]=0;
		}
	}
	
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) {
			printf("Pogresan unos!\n");
			continue;
		}
		else {
			break;
		}
	} while((M>=0 && M<=100) || (N>=0 && N<=100));
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=1; i<M; i++) {
		if(fabs(mat[i-1][N-1]-mat[i][0])>e) c=0;
			for(j=1; j<N; j++) {
				if(fabs(mat[i-1][j-1]-mat[i][j])>e) c=0;
			}
	}
	for(i=0; i<M-1; i++) {
		for(j=0; j<N-1; j++) {
			if(fabs(mat[i][j]-mat[i+1][j+1])>e) {t=0; break;}
		}
	} 

	if(c==1) {
		printf("Matrica je cirkularna");
	} else if(t==1) {
		printf("Matrica je Teplicova");
	} else {
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	
	return 0;
}
