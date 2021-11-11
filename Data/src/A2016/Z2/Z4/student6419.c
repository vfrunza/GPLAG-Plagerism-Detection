#include <stdio.h>
#include <math.h>
#define E 0.000001
int main () {
	int M, N, i, j, temp=0;
	double mat[100][100];
	int dijagonala = 0, cirkular=0, teplic=1;
	do {
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if(N<=0 || M<=0 || N>100 || M>100)
			printf("Pogresan unos!\n");
	}while(N<=0 || M<=0 || N>100 || M>100);
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
	temp=mat[0][0];
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			if(i==j && fabs(mat[i][j]-temp)>E) {
				dijagonala = 1;
				if(temp<1){
					dijagonala=0;
					cirkular=1;
				}
				break;
			}
			if(i==j && mat[i][j]==temp)
				cirkular = 1;
			if(mat[i][j]<0) {
				dijagonala=1;
				cirkular=0;
			}
		}
	}
	
	for(i=0; i<M-1; i++) {
		for(j=0; j<N; j++) {
			if(mat[i][N-1] != mat[i+1][0] && mat[i][i]!=temp) 
				dijagonala=1;
			if(mat[i][N-1] != mat[i+1][0] && mat[i][i]==temp){
				teplic=0;
				cirkular=0;
			}
		}
	}
	if(dijagonala==1) {
		printf("Matrica nije ni cirkularna ni Teplicova");
		return 1;
	}
	else if(cirkular==1){
		printf("Matrica je cirkularna");
		return 2;
	}
	else if(teplic == 0){
		printf("Matrica je Teplicova");
		return 3;
	}
	return 0;
}
