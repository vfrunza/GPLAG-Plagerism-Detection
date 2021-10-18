#include <stdio.h>
#include <math.h>
#define eps 0.00001
#define dimenzije 100

int main() {
	int i, j, M, N, T=0, C=0;
	double mat[dimenzije][dimenzije];
		printf ("Unesite M i N: ");
		scanf ("%d %d", &M, &N);
		while ((M<1 || M>100) || (N<1 || N>100)){
			printf ("Pogresan unos!\n");
			printf ("Unesite M i N: ");
			scanf ("%d %d", &M, &N);
		}
	printf ("Unesite elemente matrice: ");
	for (i=0; i<M; i++){
		for (j=0; j<N; j++){
			scanf ("%lf", &mat[i][j]);
		}
	}
	for (i=0; i<M; i++){
		if (i==(M-1)){
				break;
			}
		for (j=0; j<N; j++){
			if (j==(N-1)){
				continue;
			}
			if (fabs(mat[i][j]-mat[i+1][j+1])<eps){
				T=1;
			} else {
				T=0;
				break;
			}
		}
		if (T==0){
			break;
		}
	}
	for (i=0; i<M; i++){
		if (i==(M-1)){
			break;
		}
		for (j=0; j<N; j++){
			if (j==(N-1)){
				continue;
			}
			if (fabs(mat[i][N-1]-mat[i+1][0])<eps){
				C=1;
			} else {
				C=0;
				break;
			}
		}
		if (C==0){
			break;
		}
	}
	if (M==1 && N==1){
		printf ("Matrica je cirkularna");
		return 0;
	}
	if (N==1){
		printf ("Matrica je Teplicova");
		return 0;	
	} else if (M==1){
		printf ("Matrica je cirkularna");
		return 0;
	}

	if (T==1 && C==1){
		printf ("Matrica je cirkularna");
		return 0;
	} 
	if (T==1 && C==0){
		printf ("Matrica je Teplicova");
		return 0;
	} 
	if ((T==0 && C==0) || (T==0 && C==1)){
		printf ("Matrica nije ni cirkularna ni Teplicova");
		return 0;
	}
	return 0;
}