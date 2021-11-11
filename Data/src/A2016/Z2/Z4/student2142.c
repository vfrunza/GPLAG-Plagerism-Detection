#include <stdio.h>

int main() {
	int M, N, i, j, jeste_t=1, jeste_c=1;
	double niz[100][100];
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M>100 || N>100 || M<1 || N<1) printf("Pogresan unos!\n");
	}while(M>100 || N>100 || M<1 || N<1);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &niz[i][j]);
		}
	}
	if(N==1 && M!=1){
		printf("Matrica je Teplicova");
		return 0;
	}
	else if(M==1 && N!=1){
		printf("Matrica je cirkularna");
		return 0;
	}
	for(i=0; i<M-1; i++){
		for(j=0; j<N; j++){
			if (niz[i][j]!=niz[i+1][j+1]){
				jeste_c=0;
				jeste_t=0;
					
			}
			if((j+2)%N == 0){
				if (niz[i][j+1]!=niz[i+1][0]){
					jeste_c=0;
				}
				j = N;
			}
		}
	}
	if(jeste_c) printf("Matrica je cirkularna");
	if(jeste_c==0 && jeste_t) printf("Matrica je Teplicova");
	if(jeste_c==0 && jeste_t==0) printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}