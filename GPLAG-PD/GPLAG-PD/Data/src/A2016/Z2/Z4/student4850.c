#include <stdio.h>
#include <math.h>
#define Br 100
#define e 0.000001

int main() {
	double niz[Br][Br]={{0}};
	int M, N, i, j;
	do{
		printf ("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100) {
			printf("Pogresan unos!\n");
			continue;
		}
	} while(M<=0 || M>100 || N<=0 || N>100);
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &niz[i][j]);	
		}
	}
	if((N==1 && M==1) || (M==1 && N!=1)) {
		printf("Matrica je cirkularna");
		return 0;
	}
	if(N==1) {
		printf("Matrica je Teplicova");
		return 0;
	}
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++) {
		if(fabs(niz[i][j]-niz[i+1][j+1])>e) {
			printf("Matrica nije ni cirkularna ni Teplicova");
			return 0; }
		}
	}
	j=0;
	for(i=0; i<M-1; i++){
		if(fabs(niz[i][N-1]-niz[i+1][j])>e)
			goto labela;
		if(fabs(niz[i][j]-niz[i+1][j+1])>e) 
			goto labela;
	}
		printf("Matrica je cirkularna");
		return 0;
		labela:
		
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++) {
		if(fabs(niz[i][j]-niz[i+1][j+1])>e)
			return 0;
		}
	}
		printf("Matrica je Teplicova");
	
	return 0;
}
