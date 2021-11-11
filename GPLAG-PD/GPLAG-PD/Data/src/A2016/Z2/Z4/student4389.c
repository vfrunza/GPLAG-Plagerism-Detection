#include <stdio.h>

int main() {
	double a[100][100];
	int i, j, M, N, teplicova = 1, cirkularna = 1;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || M>100 || N<=0 || N>100){
			printf("Pogresan unos!\n");
		}
	}while(M<=0 || M>100 || N<=0 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &a[i][j]);
		}
	}
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(a[0][j]!=a[i][(i+j)%N]){
				cirkularna = 0;
			}
		}
	}
	for(i=0; i<M-1; i++){
		for(j=0; j<N; j++){
			if(j+1<N){
				if(a[i][j]!=a[i+1][j+1]){
					teplicova = 0;
				}
			}
		}
	}
	if(cirkularna==1) printf("Matrica je cirkularna");
	else if(cirkularna == 0 && teplicova == 1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}