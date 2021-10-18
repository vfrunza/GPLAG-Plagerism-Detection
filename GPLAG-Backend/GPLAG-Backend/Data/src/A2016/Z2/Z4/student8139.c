#include <stdio.h>

int main() {
	int M, N, i, j;
	double mat[100][100];
	int tep=1;
	int cir=1;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(M<=0 || N<=0 || M>100 || N>100) printf("Pogresan unos!\n");
	}while(M<=0 || N<=0 || M>100 || N>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	for(i=0; i<M-1; i++){
		for(j=0; j<N-1; j++){
			if(mat[i][j]!=mat[i+1][j+1]) {
				tep=0;
				cir=0;
			}
			if(mat[i][N-1]!=mat[i+1][0]) cir=0;
		}
	}
	if(M>1 && N==1){
		cir=0;
		tep=1;
	}
	if(cir==1) printf("Matrica je cirkularna");
	else if(tep==1) printf("Matrica je Teplicova");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
